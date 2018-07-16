//
// Created by Jérôme BUISINE on 16/07/2018.
//

#pragma once

#include "TreeNode.h"
#include <vector>

class TreeNodeExample : public TreeNode
{
public:

    // summary : Constructor of TreeNodeExample
    // parameter : @_index is the index of current node
    TreeNodeExample(unsigned _index);

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

