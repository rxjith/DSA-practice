#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

int main(void) {
    // Initialize the top of the stack to NULL
    Node *top = NULL;

    // Push elements onto the stack
    int n;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter element %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = top;
        top = newNode;
    }

    // Pop elements from the stack
    printf("Popping elements from the stack:\n");
    while (top != NULL) {
        Node *temp = top;
        printf("%d\n", top->data);
        top = top->next;
        free(temp);
    }

    return 0;
}