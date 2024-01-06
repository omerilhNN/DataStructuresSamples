#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* link;
    int data;
} *top = NULL;

void push(int data){
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){ //it is NULL when requested memory can't be allocated
        printf("Stack overflow!");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }else
        return 0;
}

int pop(){
    struct node* temp;
    temp = top;
    if(isEmpty()){
        printf("Stack underflow!");
        exit(1);
    }

    int val = temp->data;

    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}
int peek(){
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    return top->data;
}


void print(){
    struct node* temp;
    temp = top;
    printf("Stack elements are: ");
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main(){

}