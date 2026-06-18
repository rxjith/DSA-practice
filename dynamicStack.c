#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void push(Node **, int);
void pop(Node **);

int main(void) {
    // Initialize the top of the stack to NULL
    Node *top = NULL;

    // Push elements onto the stack
    int n;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        int data;
        scanf("%d", &data);
        push(&top, data);
    }

    // Pop elements from the stack
    printf("Popping elements from the stack:\n");
    for (int i = 0; i < n; i++) {
        pop(&top);
    }

    return 0;
}

void push(Node **top, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
        
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = *top;
    printf("%d\n", (*top)->data);
    *top = (*top)->next;
    free(temp);
}