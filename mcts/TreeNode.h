#pragma once

#include <vector>
#include <cmath>

/*
* Abstract class TreeNode for MCTS algorithm (UCT)
*/
class TreeNode
{

public:
	// summary : Select next node to use in the tree, expand it, run simulation and do backpropgation
	// returns : nothing
	virtual void selectAction();
	
	// summary : Specify if current tree node is a leaf or not
	// returns : boolean
	virtual bool isLeaf();
	
	// summary : Returns score from number of visits and reward
	// returns : double
	virtual double getScore()
	{
		return totalScore / nVisits;
	}

	// summary : Returns number of times node was visited
	// returns : unsigned
	virtual unsigned getNVisits()
	{
		return nVisits;
	}

	// summary : Returns total score obtained by num
	// returns : double
	virtual double getTotalScore()
	{
		return totalScore;
	}

    // summary : Returns current node index
    // returns : unsigned
    unsigned getIndex(){
        return nodeIndex;
    };

protected:

	/**************
		Methods
	**************/

	// summary : Constructor of root node
    // parameter : @_ucbParam is the ucb param to use for MCTS
    // parameter : @_problemType is the kind of problem (maximizing: true, minimizing: false)
	TreeNode(double _ucbParam, bool _problemType);

    // summary : Child node constructor
    // parameter : @_index is the index of current node
    // parameter : @_parent is the parent node to associate
    TreeNode(unsigned _index, TreeNode* _parent);

	// summary : Default destructor
	virtual ~TreeNode();

	// summary : Step 1 (expansion) : Method which selects and returns the next node from current node
	// returns : TreeNode
	virtual TreeNode* select();

	// summary : Step 2 (expansion) : open new nodes if current node is not terminal node
	// returns : nothing
	virtual void expand() = 0;

	// summary : Step 3 (simulation) : Get roll out of current node chosen
	// parameter : @_node is the node selected to get roll out
	// returns : double
	virtual double rollOut(TreeNode* _node) = 0;

	// summary : Step 4 (backprobagation) : update stats for each visited node
	// parameter : @_value reward obtained by the simulation
	// returns : double
	virtual void updateStats(double _value);

	// summary : Get the arity of current node
	// returns : unsigned
	virtual unsigned arity();

	/**************
	  Attributes
	**************/

	// children node of current node
	std::vector<TreeNode*> children;

private:

	/**************
	  Attributes
	**************/

    // Parent node of current node (if nullptr : Root Node)
    TreeNode* parent;

	// Number of visits of current node
	unsigned nVisits;

	// total score obtained for this node
	double totalScore;

    // keep in memory node index
    unsigned nodeIndex;

    // ucb EvE compromise param
    double ucbParam;

    // kind of problem (maximizing: true, minimizing: false)
    bool problemType;
};

