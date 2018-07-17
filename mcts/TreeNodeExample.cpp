#include "TreeNodeExample.h"

TreeNodeExample::TreeNodeExample(double _ucbParam, bool _problemType) : TreeNode(_ucbParam, _problemType)
{
}

TreeNodeExample::TreeNodeExample(unsigned _index, TreeNode* _parent) : TreeNode(_index, _parent)
{
}


void TreeNodeExample::expand()
{
    // For example expand always with 5 nodes
    for(unsigned i = 0; i < 5; i++){

        // create and add new node
        TreeNodeExample* node = new TreeNodeExample(i, this);
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

    // if problem we want is to minimize
    if (!problemType) {
        bestScore = MAXFLOAT;
    }

    TreeNode* childNode = nullptr;

    // find best child score based on number of times it was chosen
    for (auto child : children)
    {
        double score = child->getScore();

        // if problem we want is to maximize
        if(problemType)
        {
            if (score > bestScore)
            {
                childNode = child;

                // set next move information
                bestScore = child->getScore();
            }
        }else if (score > bestScore) {
            childNode = child;

            // set next move information
            bestScore = child->getScore();
        }
    }

    return childNode;
}