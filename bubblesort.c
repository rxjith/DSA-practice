#include <stdio.h>
#include <stdlib.h>

void bubblesort(int[], int);

int main(void) {

    int n;                                                                  // Number of elements
    printf("Enter number of elements in the array: "); scanf("%d", &n);     // User input
    
    int *arr = malloc(n*sizeof(int));                                       // Array allocation
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");                              // Failsafe checks
        return 1;
    }
    
    printf("Memory allocated successfully!\n");                             // Success message

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1); scanf("%d", (arr+i));            // Input: Array contents
    }

    printf("Array pre-sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));                                            // Output: Original array
    } printf("\n");

    printf("Sorting array...\n");
    bubblesort(arr, n);                                                     // Function call to sort array

    printf("Array post-sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));                                            // Output: Sorted array
    } printf("\n");

    free(arr);                                                              // Freeing allocated memory
    return 0;
}

void bubblesort(int arr[], int n) {
    int temp = 0;                                                           // Init: temp variable
    for (int i = 0; i < n - 1; i++) {                                       // Outer loop: each element except last    
        for (int j = 0; j < n - i - 1; j++) {                               // Inner loop: each element except checked ones
            if (*(arr+j) >= *(arr+j+1)) {                                   // Condition: If jth element >= (j+1)th element
                temp = *(arr+j);                                    
                *(arr+j) = *(arr+j+1);                                      // Basic temp var swapping
                *(arr+j+1) = temp;
            }
        }
    }
}