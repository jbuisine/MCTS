//
// Created by Jérôme BUISINE on 16/07/2018.
//

#pragma once

#include "TreeNode.h"
#include <vector>

class TreeNodeExample : public TreeNode
{
public:

    // summary : Constructor of TreeNodeExample root node
    // parameter : @_ucbParam is the ucb param to use for MCTS
    // parameter : @_problemType is the kind of problem (maximizing: true, minimizing: false)
    TreeNodeExample(double _ucbParam, bool _problemType);

    // summary : Child TreeNodeExample node constructor
    // parameter : @_index is the index of current node
    // parameter : @_parent is the parent node to associate
    TreeNodeExample(unsigned _index, TreeNode* _parent);

    // summary : Step 2 (expansion) : open new nodes (if current node is not terminal node)
    // returns : nothing
    virtual void expand();

    // summary : Step 3 (simulation) : Get roll out of current node chosen
    // parameter : @_node is the node selected to get roll out
    // returns : double
    double rollOut(TreeNode* _node);

    // summary : Returns current best tree node
    // returns : TreeNode*
    TreeNode* getBestChild();

private:

    // Here implement your own needs such like context or information to keep in node
};

