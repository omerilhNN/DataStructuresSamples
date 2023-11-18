#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


struct Queue{
    int *elements;
    int front,rear;
};

void initializeQueue(struct Queue *queue){
    queue->elements = (int *)malloc(MAX_SIZE*sizeof(int));
    queue->front = -1;
    queue -> rear = -1;
}
int isEmpty(struct Queue *queue){
    return queue->front == -1;
}
int isFull(struct Queue *queue){
    //When (rear + 1) % MAX_SIZE = 0 when front indice is 0 that means this queue is full
    return (queue-> rear+1) % MAX_SIZE == queue->front;
}
void enqueue(struct Queue *queue,int value){
    if(isFull(queue)){
        printf("Queue is full cannot add new element \n");
        return;
    }
    else{
        if(isEmpty(queue)){
            queue->front = 0;
        }
        queue-> rear = (queue-> rear +1) % MAX_SIZE;
        queue->elements[queue->rear] = value;
        printf("%d enqueued to array \n",value);
    }
}
int dequeue(struct Queue *queue){
    int value;
    if(isEmpty(queue)){
        printf("Queue is empty");
        return -1;
    }else{
        value = queue->elements[queue->front];
        if(queue->front == queue->rear){
            initializeQueue(queue); //QUEUE is Empty after dequeue(); then initialize it
        }else{
            queue->front = (queue->front + 1) % MAX_SIZE; //Increment front indice by 1 for CIRCULAR QUEUE
        }
        printf(" %d dequeued from the array: \n",value);
        return value;
    }
}
int main(){
    struct Queue *myQueue = (struct Queue*) malloc(sizeof(struct Queue));

    initializeQueue(myQueue);

    printf("\nEnter 10 elements to the queue: \n"); //Because MAX_SIZE is equals to 10
    for(int i=0; i< MAX_SIZE; i++){
        int data;
        scanf("%d",&data);
        enqueue(myQueue,data);
    }

    return 0;


}