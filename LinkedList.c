#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *link;
};

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;

    struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
    ptr->data = 98;
    ptr->link =NULL;

    head->link = ptr;
}

void countOfNodes(struct Node *head){
    int count = 0;
    if(head == NULL){
        printf("List is empty");
    }
    struct Node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("%d",count);
}

void addToEnd(struct Node *head,int data){
    struct Node *ptr,*temp;

    ptr = head;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link !=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

//adding to beginning with return type of Node*
struct Node* addToBeginning(struct Node *head,int data){
    struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    //Assign new node's link to head then assign head to this new beginning
    ptr->link = head;
    head = ptr;
    return head;
}
//adding to beginning without return type
//you need to pass 'head' by reference &head in order to call this function
void addToBeginningVoid(struct Node **head,int data){
    //**head is local to this function
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = *head; // '**' means address of a pointer -> with '*' deference it by 1

}
void addAtCertainPosition(struct Node *head,int data,int position){
    struct Node *ptr = head;

    //ptr2 is new node that we gonna add to the 'position'th position
    struct Node *ptr2 = (struct Node*)malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->link = NULL;

    position--;//you can delete here if you change while condition 'position != 2'
    while(position!=1){
        ptr = ptr->link;
        position--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

struct Node* deleteFirst(struct Node *head){
    if(head == NULL)
        printf("List is empty");
    else{
        struct Node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
//!! TODO:IMPORTANT !!
struct Node* deleteLastNode(struct Node* head){
    if(head ==NULL)
        printf("List is empty");
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct Node* temp = head;
        struct Node* temp2 = head;
        while(temp->link != NULL){
            temp2 = temp;
            temp = temp->link;
        }
        //-> Break the chain within the last node
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
void deleteLastNodeUsingSinglePointer(struct Node* head){
    if(head == NULL) printf("List is empty");
    else if(head ->link == NULL) {
        free(head);
        head = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->link->link!=NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}
void deleteAtCertainPosition(struct Node **head,int position){
    //in Main func -> deleteAtCertainPosition(&HEAD) -> give '*head' address.
    struct Node* current = *head;
    struct Node* previous = *head;
    if(*head == NULL)
        printf("List is empty");
    else if(position == 1){
        //Delete from the beginning
        *head = current -> link;
        free(current);
        current = NULL;
    }
    else{
        while(position !=1){
            previous = current;
            current = current->link;
            position--;
        }
        previous -> link = current->link;
        free(current);
        current = NULL;
    }
}
struct Node* deleteSingleLinkedList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}
// !! REVERSE !!
struct Node* reverse(struct Node *head){
    struct Node *prev = NULL; //temp => prev node
    struct Node *next = NULL;//temp2 => next node 

    while(head !=NULL){
        next = head->link; //next
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}