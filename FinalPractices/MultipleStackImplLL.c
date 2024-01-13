#include <stdio.h>
#include <stdlib.h>
#define MAX_ELM 10


struct stackNode {
    int data;
    struct stackNode* next;
};


typedef struct {
    struct stackNode* top;
}STACK;


STACK *stackArray[MAX_ELM];



void pushStack(STACK* stack, int data) {
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

}


void pushToSpecificStack(int index, int data) {
    if (index < 0 || index >= MAX_ELM) {
        printf("invalid index!\n");
        return;
    }

    STACK* targetStack = stackArray[index];
    pushStack(targetStack, data);
}


void printStacks() {
    for (int i = 0; i < MAX_ELM; ++i) {
        printf("Stack %d: ", i);
        struct stackNode* current = stackArray[i]->top;

        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {

    for (int i = 0; i < MAX_ELM; ++i) {
        stackArray[i] = (STACK*)malloc(sizeof(STACK));
        stackArray[i]->top = NULL;
    }

    pushToSpecificStack(0, 34);
    pushToSpecificStack(0, 54);
    pushToSpecificStack(0, 3);
    pushToSpecificStack(0, 6);
    pushToSpecificStack(1, 56);
    pushToSpecificStack(1, 13);
    pushToSpecificStack(6, 99);
    pushToSpecificStack(9, 67);

    printStacks();
}