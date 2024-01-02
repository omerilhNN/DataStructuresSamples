#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* addToEmpty(int data){
    struct node* temp = (struct node*)malloc(sizeof (struct node));
    temp->data =data;
    temp->next = temp;
    return temp;
}
//O(1) time complexity -> YOU DONT HAVE TO TRAVERSE ALL ELEMENTS OF THE LIST.
struct node* addAtBeginning(struct node* tail,int data){
    struct node* newP = (struct node*) malloc(sizeof (struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}
struct node* addAtEnd(struct node* tail, int data){
    struct node* newP = (struct node*) malloc(sizeof (struct node));
    newP->data = data;
    newP->next= NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}
//there is traversing list process so -> O(N) time complexity
struct node* addAfterPos(struct node* tail,int data,int pos){
    struct node* p = tail->next; //In order to traverse the list create p pointer variable
    struct node* newP =  (struct node*)malloc(sizeof (struct node));
    newP->data = data;
    newP->next = NULL;

    while(pos >1){
        //When pos equals 1 -> you are right before the given pos.
        p = p->next;
        pos--;
    }
    newP->next = p->next;
    p->next = newP;
    if(p== tail){
        tail = tail->next;
    }
    return tail;
}

void print(struct node* tail){
    if(tail == NULL)
        printf("There is no node in the list");
    else{
        struct node* p = tail->next;
        //TRAVERSING CIRCULAR LINKED LIST
        do{
            printf("%d",p->data);
            p = p->next;
        } while (p!= tail->next);
    }
    printf("\n");
}
struct node* createList(struct node* tail){
    int i,n,data;
    printf("Enter the number of nodes of linked list");
    scanf("%d",&n);

    if(n==0)
        return tail;
    printf("Enter the element 1: ");
    scanf("%d",&data);
    tail = addToEmpty(data);

    for(i =1;i<n;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&data);
        tail = addAtEnd(tail,data);
    }
    return tail;
}
struct node* deleteFirst(struct node* tail){
    if(tail == NULL){
        return tail;
    }
    if(tail->next == tail){//if there is only one node
        free(tail);
        tail == NULL;
        return tail;
    }
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
struct node* delLast(struct node* tail){
    if(tail == NULL)
        return tail;
    struct node* temp = tail->next; //IN ORDER TO TRAVERSE THE LIST. -> points to beginning of the list.
    if(tail->next = tail){
        //there is only one node.
        free(tail);
        tail = NULL;
        return tail;
    }
    while(temp->next != tail){//Traverse until reach the node that is right before the last node.
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}
int main(){
    struct node* tail = NULL;
//    tail = addToEmpty(45);
//    tail = addAtBeginning(tail,32);
//    tail = addAtEnd(tail,22);
//    tail = addAtEnd(tail,5);
//
//    print(tail);
//    tail = addAfterPos(tail,66,2);
//    print(tail);

    tail = createList(tail);
    printf("\nList before deletion");
    print(tail);

    tail = deleteFirst(tail);
    printf("\nList after deletion");
    print(tail);

    return 0;
}