#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void RemoveDuplicates (struct Node * head)
{
    struct Node * temp1, * temp2, * prev;
    temp1=head;
    while(temp1!=NULL)
    {
        temp2=temp1->next;
        prev = temp1;
        while(temp2!=NULL)
        {
            if(temp1->data == temp2->data)
            {
                //delete
                prev->next = temp2->next;
                free(temp2);
                temp2 = temp2->next;
            }
            else
            {
                prev = temp2;
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }
}

int main(){

}