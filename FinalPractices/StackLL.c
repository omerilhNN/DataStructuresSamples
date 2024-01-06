#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct stackT {
    Node* top;
    int maxSize;  // max number of items allowed in the stack
    int count;    // current number of items in the stack
} stackT;

int StackIsEmpty(struct stackT* mystack) {
    return mystack->count ==0;
}

int StackIsFull(stackT* mystack) {
    return mystack->count == mystack->maxSize;
}

void StackPush(stackT* mystack, int element) {
    if (StackIsFull(mystack)) {
        printf("Can't push element on stack: stack is full.\n");
        exit(1); /* Exit, returning error code. */
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = mystack->top;
    mystack->top = newNode;
    mystack->count++;
}

int StackPop(stackT* mystack) {
    if (StackIsEmpty(mystack)) {
        printf(" Can't pop element stack is empty.\n");
        exit(1); /* Exit, returning error code. */
    }

    Node* temp = mystack->top;
    int data = temp->data;
    mystack->top = temp->next;
    free(temp);
    mystack->count--;

    return data;
}

int main() {
    stackT mystack; /* A stack to hold ints. */
    mystack.maxSize = 10;
    mystack.count = 0;
    mystack.top = NULL;

    StackPush(&mystack, 5);
    StackPush(&mystack, 1);
    StackPush(&mystack, 7);

    printf("%d\n", StackPop(&mystack));
    printf("%d\n", StackPop(&mystack));
    printf("%d\n", StackPop(&mystack));

    return 0;
}
