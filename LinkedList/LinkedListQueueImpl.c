#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*) malloc(sizeof (struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue){
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue,int data){
    struct Node* temp = (struct Node*)malloc(sizeof (struct Node));
    temp->data = data;
    temp->next = NULL;

    if(isEmpty(queue)){
        //if queue is empty set both front and rear to the new node.
        queue->front = temp;
        queue->rear = temp;
    }else{//Otherwise, add the new node to the rear of the queue.
        queue->rear->next = temp;
        queue->rear = temp;
    }
}
// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        // If the queue is empty, return an error value (e.g., -1)
        return -1;
    }

    // Remove the front node from the queue and get its data
    struct Node* temp = queue->front;
    int data = temp->data;

    // Update the front of the queue
    queue->front = temp->next;

    // If the front becomes NULL after dequeue, update the rear to NULL as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);

    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Queue elements: ");
    printQueue(queue);

    int dequeuedValue = dequeue(queue);
    if (dequeuedValue != -1) {
        printf("Dequeued element: %d\n", dequeuedValue);
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
    }

    printf("Updated Queue elements: ");
    printQueue(queue);

    return 0;
}