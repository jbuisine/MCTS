#include <TreeNodeExample.h>
#include <random>

TreeNodeExample::TreeNodeExample(double _ucbParam) : TreeNode(_ucbParam)
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
        auto node = new TreeNodeExample(i, this);
        children.push_back(node);
    }
}

double TreeNodeExample::rollOut(TreeNode* _node)
{
    // default roll out for example
    return ((double) rand() / (RAND_MAX)) * 10;
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