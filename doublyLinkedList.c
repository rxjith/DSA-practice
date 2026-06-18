#include <stdio.h>
#include <stdlib.h>

// Allocate memory for the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {

    // Allocate memory for two nodes in the doubly linked list
    Node *node1 = (Node*)malloc(sizeof(Node));
    Node *node2 = (Node*)malloc(sizeof(Node));

    // Initialize the data for the nodes
    node1->data = 10;
    node2->data = 20;

    // Link the nodes together
    node1->prev = NULL; node1->next = node2;
    node2->prev = node1; node2->next = NULL;

    // Print the data of the nodes
    printf("Node 1 data: %d\n", node1->data);
    printf("Node 2 data: %d\n", node1->next->data);

    // Free the allocated memory for the nodes
    free(node1);  
    free(node2);

    return 0;

}