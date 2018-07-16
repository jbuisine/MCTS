//
// Created by Jérôme BUISINE on 16/07/2018.
//

#include <iostream>
#include <TreeNodeExample.h>

int main () {

    unsigned numberOfIterations = 100;

    TreeNodeExample* rootNode = new TreeNodeExample(0);

    for(unsigned i = 0; i < numberOfIterations; i++){
        rootNode->selectAction();
    }

    // TODO : check link issue
    TreeNode* nextNodeToUse = rootNode->getBestChild();
    unsigned nodeIndex = nextNodeToUse->getIndex();

    delete rootNode;

    std::cout << "Next node to use is [Node " << nextNodeToUse << "]" << std::endl;

}