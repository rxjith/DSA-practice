#include <stdio.h>
#include <stdlib.h>

void insertionsort(int[], int);

int main(void) {
    int n;
    printf("Enter number of elements in the array: "); scanf("%d", &n);
    
    int *arr = malloc(n*sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Memory allocated successfully!\n");

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1); scanf("%d", (arr+i));
    }

    printf("Array pre-sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    } printf("\n");

    printf("Sorting array...\n");
    insertionsort(arr, n);

    printf("Array post-sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    } printf("\n");

    free(arr);
}

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = *(arr+i);
        int j = i - 1;
        while (j >= 0 && *(arr+j) > key) {
            *(arr+j+1) = *(arr+j);
            j--;
        } *(arr+j+1) = key;
    }
}