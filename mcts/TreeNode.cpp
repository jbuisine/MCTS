#include <TreeNode.h>
#include <random>

TreeNode::TreeNode(double _ucbParam) : parent(nullptr), nVisits(0), totalScore(0.), nodeIndex(0),
                                                          ucbParam(_ucbParam), children(std::vector<TreeNode*>())
{
}

TreeNode::TreeNode(unsigned _index, TreeNode* _parent) : parent(_parent), nVisits(0), totalScore(0.), nodeIndex(_index),
                                                         children(std::vector<TreeNode*>())
{
    if(_parent){
        this->ucbParam = _parent->ucbParam;
    }else{
        throw "Cannot create child node without valid parent node...";
    }
}


TreeNode::~TreeNode()
{
	for (auto child : children)
	{
		delete child;
	}
}

void TreeNode::selectAction()
{
	auto visited = std::vector<TreeNode*>();

	// getting current node
	TreeNode* currentNode = this;

	visited.push_back(currentNode);

	// while current node is not unexplored node
	while (!currentNode->isLeaf())
	{
		currentNode = currentNode->select();
		visited.push_back(currentNode);
	}

	// expand new selected current node leaf
	currentNode->expand();

	double value = 0.;
	
	// check if we cannot expand current node (final node)
	if (currentNode->isLeaf())
	{
		// add default score of current node
		value = rollOut(currentNode);
	}
	else
	{
		// select node from the new open node
		TreeNode* newNode = currentNode->select();
		visited.push_back(newNode);

		value = rollOut(newNode);
	}

	for(auto node : visited)
	{
		// update score of each node
		node->updateStats(value);
	}
}

bool TreeNode::isLeaf()
{
	return children.empty();
}

void TreeNode::updateStats(double _value)
{
	nVisits++;
	totalScore += _value;
}

unsigned TreeNode::arity()
{
	return static_cast<unsigned int>(children.empty() ? 0 : children.size());
}

TreeNode* TreeNode::select()
{
	// by default initialize with empty node
	TreeNode* selected = nullptr;

	// initialize value
	double bestValue = 0.;

	// First check unvisited node
	auto unvisitedNodeIndex = std::vector<unsigned>();
	unsigned index = 0;

	unsigned childrenVisits = 0;

	for (auto child : children)
	{
		if (child->nVisits == 0)
		{
			unvisitedNodeIndex.push_back(index);
		}

		childrenVisits += child->nVisits;

		index++;
	}

	unsigned nbUnvisited = static_cast<unsigned int>(unvisitedNodeIndex.size());

	if (nbUnvisited > 0)
	{
		// choose randomly 1 node from unvisited node
		unsigned indexChoice = rand() % nbUnvisited;

		// return child choice
		return children.at(unvisitedNodeIndex.at(indexChoice));
	}
	else
	{
		// all nodes are visited once, now we can exploit UCB1 formula
		for (auto child : children)
		{
			double uctValue = child->getScore() + ucbParam * sqrt(log(childrenVisits) / (child->nVisits));

			double prob = ((double) rand() / (RAND_MAX));

            // check all cases of problem update
            if(uctValue > bestValue || (uctValue == bestValue && prob < 0.5)){

                selected = child;
                bestValue = uctValue;
            }
        }
	}

	return selected;
}
