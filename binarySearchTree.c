#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;  // Points to smaller values
    struct Node* right; // Points to larger values
} Node;

Node* createNode(int);
Node* insert(Node*, int);
void inOrderTraversal(Node*);
bool search(int, Node*);
void freeTree(Node*);

int main(void) {

    Node *root = NULL;
    
    int n, child;
    printf("Enter number of elements you want to insert into the tree: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &child);
        root = insert(root, child);
    }

    if (root != NULL) {
        printf("Tree built successfully! Root node is %d\n", root->data);
    }
    printf("Tree elements:\n");
    inOrderTraversal(root);
    printf("\n");

    freeTree(root);
    printf("Tree has been freed of nodes and released back to memory!\n");
    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

bool search(int target, Node* root) {
    if (root == NULL) {
        return false;
    }

    if (target == root->data) {
        return true;
    }

    else if (target < root->data) {
        return search(target, root->left);
    }
    
    else if (target > root->data) {
        return search(target, root->right);
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}