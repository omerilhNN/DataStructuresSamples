#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function to initialize a new stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a value onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    int value = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return value;
}

// Function to add two numbers represented by linked lists using stacks
struct Node* addNumbers(struct Node* num1, struct Node* num2) {
    struct Stack stack1, stack2, resultStack;
    initializeStack(&stack1);
    initializeStack(&stack2);
    initializeStack(&resultStack);

    // Push digits of the first number onto stack1
    while (num1 != NULL) {
        push(&stack1, num1->data);
        num1 = num1->next;
    }

    // Push digits of the second number onto stack2
    while (num2 != NULL) {
        push(&stack2, num2->data);
        num2 = num2->next;
    }

    int carry = 0;

    // Pop digits from stack1 and stack2, add them along with carry, and push the result onto resultStack
    while (!isEmpty(&stack1) || !isEmpty(&stack2) || carry != 0) {
        int sum = carry;

        if (!isEmpty(&stack1)) {
            sum += pop(&stack1);
        }

        if (!isEmpty(&stack2)) {
            sum += pop(&stack2);
        }

        carry = sum / 10;
        sum %= 10;

        push(&resultStack, sum);
    }

    // Build the result linked list from the resultStack
    struct Node* result = NULL;

    while (!isEmpty(&resultStack)) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = pop(&resultStack);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

// Function to display a linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory allocated for a linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example numbers represented as linked lists
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    // Fill in the blanks with the digits of the numbers
    // For example, to represent the number 123, you would do:
    // num1 = pushDigit(num1, 3);
    // num1 = pushDigit(num1, 2);
    // num1 = pushDigit(num1, 1);

    // Similarly, fill in the blanks for num2

    // Display the original numbers
    printf("Number 1: ");
    displayList(num1);
    printf("Number 2: ");
    displayList(num2);

    // Add the numbers and display the result
    struct Node* result = addNumbers(num1, num2);
    printf("Sum: ");
    displayList(result);

    // Free memory allocated for linked lists
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}
