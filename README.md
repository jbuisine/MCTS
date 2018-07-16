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
- rollOut(TreeNode* _node) : what is your simulation and roll out

You can also redefine other methods if necessary. Note that by default, TreeNode use UCB for maximizing problem. If you want, you can redefine these two methods too :
- select() : selection method of next node to explore (UCB1 formula for example)
- getBestChildResult() : what is for you the best child result

## Contributors

* [jbuisine](https://github.com/jbuisine)

## Licence

[MIT](https://github.com/jbuisine/MCTS/blob/master/LICENSE)
