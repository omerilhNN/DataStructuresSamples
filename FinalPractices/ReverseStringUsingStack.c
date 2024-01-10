#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(struct Stack* stack,char *input) {
    // Push each character onto the stack
    for (int i = 0; i < strlen(input); i++) {
        push(stack, input[i]);
    }

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < strlen(input); i++) {
        input[i] = pop(stack);
    }
}

int main() {
    char originalString[] = "Hello, World!";
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(stack);

    printf("Original String: %s\n", originalString);

    // Reverse the string
    reverseString(stack,originalString);

    printf("Reversed String: %s\n", originalString);

    return 0;
}
