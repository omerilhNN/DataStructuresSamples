#include <stdio.h>
#include <stdlib.h>


struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addToEmpty(int data){
    struct node* temp = (struct node*)malloc(sizeof (struct node*));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node* addAtBeginning(struct node* tail,int data){
    struct node* newP = addToEmpty(data);
    if(tail == NULL){
        return newP;
    }
    else {
        struct node* temp = tail->next;//Initialize it from the beginning of the list.
        newP->prev = tail;
        newP->next = temp;
        temp->prev = newP;
        tail->next = newP;
        return tail;
    }
}
struct node* addAtEnd(struct node* tail,int data){
    struct node* newP = addToEmpty(data);
    if(tail == NULL){
        return newP;
    }
    else{
        struct node* temp = tail->next;
        newP->next = temp;
        newP->prev = tail;
        tail->next = newP;
        temp->prev = newP;
        tail = newP;
        return tail;
    }
}
struct node* addAfterPos(struct node* tail,int data,int pos){
    struct node* newP = addToEmpty(32);
    if(tail == NULL)
        return newP;
    struct node* temp = tail->next;
    while(pos >1 ){
        temp = temp->next;
        pos--;
    }
    newP->prev = temp;
    newP->next = temp->next;
    temp->next->prev = newP;
    temp->next = newP;
    if(temp == tail){
        tail = tail->next;
    }
    return tail;
}
struct node* deleteFirst(struct node* tail){
    if(tail == NULL) return tail;
    struct node* temp = tail->next;
    if(temp == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    return tail;
}
struct node* deleteLast(struct node* tail){
    struct node *temp = NULL;
    if(tail == NULL){
        return tail;
    }
    if(temp == tail){// There is only 1 node in the LL.
        free(tail);
        tail = NULL;
        return tail;
    }
    temp = tail->prev; // SECOND LAST NODE OF THE LIST
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    return tail;
}
void print(struct node* tail){
    if(tail == NULL){
        printf("There is no element in the list \n");
    }else{
        struct node* temp = tail->next;
        do{
            printf("%d",temp->data);
            temp = temp->next;
        }while(temp!=tail->next);
    }
    printf("\n");

}

int main(){
    struct node* tail = NULL;
    tail = addToEmpty(44);
    tail = addAtBeginning(tail,35);
    tail = addAtEnd(tail,49);

    print(tail);
    return 0;
}