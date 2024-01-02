#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    int capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character to the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    int length = strlen(str);
    struct Stack* stack = createStack(length);

    // Push each character onto the stack
    for (int i = 0; i < length; i++)
        push(stack, str[i]);

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < length; i++)
        str[i] = pop(stack);

    free(stack->array);
    free(stack);
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Reverse the string
    reverseString(input);

    printf("Reversed string: %s\n", input);

    return 0;
}
