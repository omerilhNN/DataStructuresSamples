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
        BandMatrix.c
        Test.c
        LowerTriangularMatrix.c
        UpperTriangularMatrix.c
        LinkedList/LinkedList.c
        LinkedList/DoublyLinkedList.c
        LinkedList/LinkedListStackImpl.c
        ReverseStringStack.c
        LinkedList/ReverseLinkedListUsingStack.c
        LinkedList/LinkedListQueueImpl.c
        LinkedList/PolynomialArithmetic.c
        LinkedList/AdditionTwoPolynomial.c
        LinkedList/CircularLinkedList.c
        Trees/BinarySearchTree.c
        FinalPractices/StackLL.c
        FinalPractices/SumDigits.c
        FinalPractices/PrintLevelBST.c
        FinalPractices/ReverseStringUsingStack.c
        LinkedList/CircularDoublyLinkedList.c
        LinkedList/Recursion_ReverseLinkedList.c
        FinalPractices/MultipleStackImplLL.c)
