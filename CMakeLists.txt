cmake_minimum_required(VERSION 3.26)
project(DataStructuresSamples C)

set(CMAKE_C_STANDARD 11)

add_library(DataStructuresSamples library.c
        FibonacciSequence.c
        PermutationProblem.c
        DiagonalMatrix.c
        FibonacciRecursive.c
        CircularQueue.c
        StandardQueue.c
        Stack.c
        BandMatrix.c)
