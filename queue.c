#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node**, Node**, int);
void dequeue(Node**, Node**);

int main(void) {
    int n;
    Node* front = NULL; 
    Node* rear = NULL;
    
    printf("Enter number of elements you want to enter into the queue: ");
    scanf("%d", &n);

    printf("Queuing elements into the queue:\n");
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &data);
        enqueue(&front, &rear, data);
    }

    printf("Dequeuing elements from the queue:\n");
    for (int i = 0; i < n; i++) {
        dequeue(&front, &rear);
    } printf("\n");

    return 0;
}

void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Queue underflow (Queue's empty)!\n");
        return;
    }
    Node *temp = *front;
    printf("%d ", (*front)->data);
    *front = (*front)->next;
    free(temp);

    if (*front == NULL) {
        *rear = NULL;
        return;
    }
}