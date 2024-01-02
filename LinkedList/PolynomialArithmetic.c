#include <stdio.h>
#include <stdlib.h>

struct node{
    float coefficient;
    int exponent;
    struct node *link;
};





struct node *insert(struct node *head, float coefficient, int expo) {
    struct node* temp;
    struct node* newP = (struct node*)malloc(sizeof (struct node));
    newP -> coefficient = coefficient;
    newP-> exponent = expo;
    newP-> link = NULL;

    if(head == NULL || expo > head->exponent){
        //list is empty or exponent of newP is greater than the head Node;
        newP->link =head;
        head = newP;
    }
    else{
        temp = head;
        while(temp -> link != NULL && temp->link->exponent > expo)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return newP;
}
struct node* create(struct node* head){
    int n;
    int i,expo;
    float coefficient;

    printf("Enter the number of terms : ");
    scanf("%d",&n);

    for(i=0; i<n;i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&coefficient);

        printf("Enter the expo for term %d: ",i+1);
        scanf("%d",&expo);
        head = insert(head,coefficient,expo);
    }

}
void print(struct node* head){
    if(head == NULL){
        printf("No polnomial");
    }
    else{
        struct node* temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
            temp = temp->link;
            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }

}

int main(){

}