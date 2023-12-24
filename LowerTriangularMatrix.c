#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];


struct Queue{
    int front;
    int rear;
};

void initializeQueue(struct Queue *firstQueue, struct Queue *secondQueue){
    firstQueue->front = 0;
    firstQueue->rear = 0;

    secondQueue->front = 10;
    secondQueue -> rear = 10;

}

void enqueue(struct Queue *firstQueue,struct Queue *secondQueue,int queueNum, int value) {
    if (queueNum == 1) {
        if (firstQueue->rear == MAX_SIZE) {
            printf("Queue 1 is full.\n");
            return;
        }
        queue[firstQueue->rear++] = value;
    } else if (queueNum == 2) {
        if (secondQueue->rear == MAX_SIZE) {
            printf("Queue 2 is full.\n");
            return;
        }
        queue[secondQueue->rear++] = value;
    } else {
        printf("Invalid queue number.\n");
    }
}

void dequeue(struct Queue *firstQueue,struct Queue *secondQueue,int queueNum) {
    if (queueNum == 1) {
        if (firstQueue->front == firstQueue->rear) {
            printf("Queue FIRST is empty.\n");
            return;
        }
        firstQueue->front++;
    } else if (queueNum == 2) {
        if (secondQueue->front == secondQueue->rear) {
            printf("Queue SECOND is empty.\n");
            return;
        }
        secondQueue->front++;
    } else {
        printf("Invalid queue number.\n");
    }
}

void printQueue(struct Queue *firstQueue, struct Queue *secondQueue,int queueNum) {
    int front, rear;

    if (queueNum == 1) {
        printf("QUEUE: FIRST FRONT:%d REAR:%d SIZE:%d\n", firstQueue->front, firstQueue->rear, (firstQueue->rear) - (firstQueue->front));

    } else if (queueNum == 2) {
        printf("QUEUE: SECOND FRONT:%d REAR:%d SIZE:%d\n", secondQueue->front, secondQueue->rear, (secondQueue->rear) - (secondQueue->front));
    } else {
        printf("Invalid queue number.\n");
        return;
    }

    if (firstQueue->front == firstQueue->rear || secondQueue->front == secondQueue->rear) {
        printf("NO_CONTENT\n");
        return;
    }

    if(queueNum ==1 ){
        printf("QUEUE FIRST: ");
        for(int i = firstQueue->front; i< firstQueue-rear; i++){
            printf("%d",queue[i]);
      }
    }else if(queueNum == 2){
        printf("QUEUE SECOND: ");
        for(int j = secondQueue->front; j < secondQueue->rear; j++){
            printf("%d",queue[j]);
        }
    }
    printf("\n");
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    char command[20];
    char queueName[10];
    int value;

    struct Queue *firstQueue,*secondQueue;

    initializeQueue(firstQueue,secondQueue);

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "ENQUEUE") == 0) {
            fscanf(file, "%s %d", queueName, &value);
            int queueNum = (queueName[0] == 'F') ? 1 : 2;
            enqueue(firstQueue,secondQueue,queueNum, value);
        } else if (strcmp(command, "DEQUEUE") == 0) {
            fscanf(file, "%s", queueName);
            int queueNum = (queueName[0] == 'F') ? 1 : 2;
            dequeue(firstQueue,secondQueue,queueNum);
        } else if (strcmp(command, "PRINT") == 0) {
            fscanf(file, "%s", queueName);
            int queueNum = (queueName[0] == 'F') ? 1 : 2;
            printQueue(firstQueue,secondQueue,queueNum);
        }
    }

    fclose(file);
    return 0;
}
