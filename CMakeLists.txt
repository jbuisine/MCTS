cmake_minimum_required(VERSION 2.8)
project(MCTS)

include_directories(mcts)

file(GLOB mcts_SRC
        "mcts/*.h"
        "mcts/*.cpp"
        )

add_executable(MCTSExample mainExample.cpp ${mcts_SRC})