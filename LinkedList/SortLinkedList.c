#include <stdio.h>
#include <stdlib.h>

// Linked list düğümü tanımı
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturmak için yardımcı fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Linked list'i sıralı hale getiren fonksiyon
void sortLinkedList(struct Node** head) {
    struct Node *sortedList = NULL;
    struct Node *current = *head;
    struct Node *next;

    // Birincil linked list üzerinde dön
    while (current != NULL) {
        next = current->next;

        // Sıralı listeyi güncelle
        if (sortedList == NULL || sortedList->data >= current->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            struct Node* temp = sortedList;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        // Bir sonraki düğüme geç
        current = next;
    }

    // Sıralı liste ile başlangıç listesini değiştir
    *head = sortedList;
}

// Linked list'i yazdırmak için yardımcı fonksiyon
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Test fonksiyonu
int main() {
    struct Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(7);

    printf("Sırasız Linked List: ");
    printLinkedList(head);

    sortLinkedList(&head);

    printf("Sıralı Linked List: ");
    printLinkedList(head);

    return 0;
}
