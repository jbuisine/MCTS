#include "TreeNodeExample.h"

TreeNodeExample::TreeNodeExample(unsigned _index) : TreeNode(_index)
{
}

void TreeNodeExample::expand()
{
    // For example expand always with 5 nodes
    for(unsigned i = 0; i < 5; i++){

        // create and add new node
        TreeNodeExample* node = new TreeNodeExample(i);
        children.push_back(node);
    }
}

double TreeNodeExample::rollOut(TreeNode* _node)
{
    // default roll out for example
    return rand() % 15 + 5;
}

TreeNode* TreeNodeExample::getBestChild()
{
    double bestScore = 0.;
    TreeNode* childNode = nullptr;

    // find best child score based on number of times it was chosen
    for (auto child : children)
    {
        double score = child->getScore();

        if (score > bestScore)
        {
            childNode = child;

            // set next move information
            bestScore = child->getScore();
        }
    }

    return childNode;
}