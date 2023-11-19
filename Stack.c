#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10

struct Stack{
    int items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack){
    stack -> top = -1;
}
int isEmpty(struct Stack *stack){
    return stack->top == -1;
}
int isFull(struct Stack *stack){
    return stack -> top == MAX_SIZE-1;
}
void push(struct Stack *stack,int value){
    if(isFull(stack)){
        printf("Stack overflow \n");
    }else{
        stack->top++;
        stack->items[stack->top] = value;
        printf("%d pushed to stack \n", value);
    }
}
int pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return 0;
    }else{
        return stack->items[stack->top--]; //Return element at the TOP and decrement it by 1 .
    }

}
//Function to get top element without removing it from the stack.
int peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }else{
        return stack->items[stack->top];
    }
}
int main(){
    struct Stack* stack = (struct Stack*)malloc(sizeof (struct Stack));

    initialize(stack);

    push(stack,10);
    printf("Top element is %d\n", peek(stack));
    push(stack,20);
    printf("Top element is %d\n", peek(stack));
    push(stack,30);
    printf("Top element is %d\n", peek(stack));
    push(stack,40);
    printf("Top element is %d\n", peek(stack));

    pop(stack);
    printf("Top element is %d\n", peek(stack)); //30
    pop(stack);
    printf("Top element is %d\n", peek(stack));//20

}
