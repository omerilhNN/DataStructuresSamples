#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addToEmptyList(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp-> prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}
struct node* addAtBeginning(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp-> prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}
struct node* addAtEnd(struct node* head,int data){
    struct node *temp,*tp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    //tp for TRAVERSE
    tp = head;
    //TRAVERSING THE LIST.
    while(tp->next != NULL){
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}
struct node* addAfterGivenPos(struct node* head,int data,int position){
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmptyList(newP,data);

    while (position != 1){
        temp = temp-> next;
        position--;
    }
    //temp is previous position and temp2 is next position of newP
    //place newP in between temp and temp2
    if(temp->next == NULL){
        temp->next = newP;
        newP->prev = temp;
    }
    else{
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}
struct node* addBeforeGivenPos(struct node* head, int data, int pos){
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;

    //newP is the node that we are gonna add to the list before given pos
    newP = addToEmptyList(newP,data);
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    if(pos == 1)
        head = addAtBeginning(head,data);
    else{
        temp2 = temp->next;
        temp-> next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}

int main() {
    struct node *head = NULL;
    //Insertion to empty List.
    head = addToEmptyList(head,45);
    printf("%d",head->data);

    //Insertion at the beginning.
    head = addAtBeginning(head,34);

    //Insertion at the end of the list.
    head = addAtEnd(head,99);

    //Insertion before given position
    head = addBeforeGivenPos(head,22,3);
    //Insertion after given position
    head = addAfterGivenPos(head,14,2);


    return 0;

}
