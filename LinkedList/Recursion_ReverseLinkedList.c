#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int data;

};
struct node* head;

struct node* reverse(struct node* current, struct node* prev){
    if(current == NULL){
        head = prev;
        return prev;
    }
    struct node* nextNode = current->next;
    current->next = prev;
    reverse(nextNode,current);

    return NULL;
}
void print(struct node* head){
    while(head !=NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("NULL");
}

int main(){

}