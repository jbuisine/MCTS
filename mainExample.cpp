//
// Created by Jérôme BUISINE on 16/07/2018.
//

#include <iostream>
#include <TreeNodeExample.h>

int main () {

    srand(static_cast<unsigned int>(time(NULL)));

    unsigned numberOfIterations = 1000;

    auto rootNode = new TreeNodeExample(sqrt(2));

    for(unsigned i = 0; i < numberOfIterations; i++){
        rootNode->selectAction();

        std::cout << "---------- Iteration " << i << "----------------------" << std::endl;

        // display score information of each sub node
        for(auto node : rootNode->getChildren()){
            std::cout << "Node " << node->getIndex() << " (visited : " << node->getNVisits() << ")"
                                 << " : " << node->getScore() << std::endl;
        }
    }

    TreeNode* nextNodeToUse = rootNode->getBestChild();
    unsigned nodeIndex = nextNodeToUse->getIndex();

    delete rootNode;

    std::cout << std::endl << "----- Result -------------------" << std::endl;
    std::cout << "Next node to use is [Node " << nextNodeToUse->getIndex() << "]" << std::endl;

}