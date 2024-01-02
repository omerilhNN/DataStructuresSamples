#include <stdio.h>
#include <stdlib.h>

struct node{
    float coeff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,float co, int ex){
    struct node* temp;
    struct node* newP = (struct node*) malloc(sizeof (struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    //If there is no node in the list or given exponent is greater than the first node EXPO.
    if(head == NULL|| ex > head->expo){
        newP->link = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp->link !=NULL && temp->link->expo >= ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
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
void polyAdd(struct node *head1, struct node *head2) {
    struct node* ptr1=NULL;
    struct node* ptr2=NULL;
    struct node* head3 = NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){ //If expo'S are equal -> add COEFF'S and continue traversing the list
            head3 = insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            //If ptr1's expo is greater than the ptr2's expo then just traverse ptr1
            head3 = insert(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo){
            head3 = insert(head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        head3 = insert(head3,ptr1->coeff,ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->link;
    }

}



int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Please enter the first poly\n");
    head1 = create(head1);
    printf("Please enter the second poly \n");
    head2 = create(head2);

    polyAdd(head1,head2);
    return 0;
}

