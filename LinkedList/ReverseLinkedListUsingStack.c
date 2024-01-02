#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the stack
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* newNode) {
    //ADD NODE -> ON TOP OF THE STACK's TOP
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    struct Node* temp = stack->top;
    stack->top = stack->top->next; //change STACK's TOP position
    temp->next = NULL;
    return temp;
}

// Function to reverse a linked list using a stack
void reverseLinkedList(struct Node** head) {
    if (*head == NULL) {
        return; // Empty list, nothing to reverse
    }

    struct Stack* stack = createStack();
    struct Node* current = *head;

    // Push all elements onto the stack
    while (current != NULL) {
        push(stack, current);
        current = current->next;
    }

    // Pop elements from the stack and update the linked list
    *head = pop(stack);
    current = *head;
    while (!isEmpty(stack)) {
        current->next = pop(stack);
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("Original Linked List: ");
    printList(head);

    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
