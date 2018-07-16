#include "TreeNode.h"

TreeNode::TreeNode(unsigned _index) : nVisits(0), totalScore(0.), nodeIndex(_index), children(std::vector<TreeNode*>())
{
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
	return children.empty() ? 0 : children.size();
}

TreeNode* TreeNode::select()
{
	// by default initialize with empty node
	TreeNode* selected = nullptr;

	// for maximizing problem
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

	unsigned nbUnvisited = unvisitedNodeIndex.size();

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
            // TODO : possibility to change UCB params
			double c = sqrt(2.);
			double uctValue = (child->totalScore / (child->nVisits)) + sqrt(50.) * sqrt(log(child->nVisits) / (childrenVisits));
			double prob = rand() % RAND_MAX;

			// choose only if better or randomly if equal
			if (uctValue > bestValue || (uctValue == bestValue && prob < 0.5))
			{
				selected = child;
				bestValue = uctValue;
			}
		}
	}

	return selected;
}
