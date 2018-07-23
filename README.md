# MCTS
Simple implementation of MCTS (UCT) algorithm

## Installation

It's a cmake project, so if you want to run example you only need to :

```commandline
mkdir build
```

```commandline
cd build
```

And then :
```commandline
cmake ..
```

## How to use

If you want to implement your own version of MCTS
```c++
#include TreeNode.h
```

You have to define the abstract methods :
- expand() : how you expand your problem (depend of your context)
- rollOut(TreeNode* _node) : what is your simulation and roll out returned
- getBestChild() : what is for you the best child result

Note that by default, TreeNode abstract class use UCB selection :
- select() : selection method of next node to explore (UCB1 formula currently)

## Contributors

* [jbuisine](https://github.com/jbuisine)

## Licence

[MIT](https://github.com/jbuisine/MCTS/blob/master/LICENSE)
