#include <stdio.h>
#include <stdlib.h>

void sorter(int[], int);
void bubbleSort(int[], int);
int binarySearch(int, int, int, int[]);

int main(void) {
    
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1); scanf("%d", (arr + i));
    }

    int key;
    printf("Enter element to search for within the array: ");
    scanf("%d", &key);

    sorter(arr, n);
    int index = binarySearch(0, n - 1, key, arr);
    if (index != -1) {
        printf("%d was found within the array at position %d.\n", key, index + 1);
    } else {
        printf("%d was NOT found within the array.\n", key);
    }

    free(arr);
    return 0;
}

void sorter(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Array unsorted, now sorting...\n");
            bubbleSort(arr, size);
            break;
        }
    }
}

void bubbleSort(int arr[], int size) {
    int temp, swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}

int binarySearch(int left, int right, int key, int arr[]) {

    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (key == arr[mid]) {
        return mid;
    }

    else if (key < arr[mid]) {
        return binarySearch(left, mid - 1, key, arr);
    }

    else if (key > arr[mid]) {
        return binarySearch(mid + 1, right, key, arr);
    }

}