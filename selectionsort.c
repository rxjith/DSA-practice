#include <stdio.h>
#include <stdlib.h>

void selectionSort(int[], int);

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
    selectionSort(arr, n);

    printf("Array post-sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    } printf("\n");

    free(arr);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}