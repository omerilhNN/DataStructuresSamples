#include  <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue{
    int *items;
    int size;
    int front;
    int rear;
};

void initializeQueue(struct Queue* queue,int size){
    queue->size = size;
    queue->front = -1;
    queue -> rear = -1;
    queue->items = (int * )malloc(size*sizeof(int));
}
void enqueue(struct Queue *queue,int value){
    if(queue->rear == queue->size -1) {
        printf("Queue is full");
        return;
    }
    else{
        queue-> rear++;
        queue->items[queue->rear] = value;
    }
}
int dequeue(struct Queue* queue){
    int x=-1;
    if(queue->front == queue->rear){
        printf("Queue is empty");
    }
    else{
        x = queue->items[queue->front];
        queue->front++;
    }
    return x; //return deleted item.
}
void display(struct Queue* queue){
    int i;
    for(i =0; i<=(queue->rear); i++){
        printf("%d ",queue->items[i]);
    }
    printf("\n");
}
int main(){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    int size;

   printf("Enter the max Size of your queue: ");
   scanf("%d",&size);

   initializeQueue(queue,size);

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);

    display(queue);

    dequeue(queue);

    display(queue);

}
