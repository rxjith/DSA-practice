#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int l, int h);
void quickSort(int arr[], int l, int h);

int main(void)
{
    int n;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocated successfully!\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array pre-sort: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorting array...\n");

    quickSort(arr, 0, n - 1);

    printf("Array post-sort: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l + 1;
    int j = h;

    while (1)
    {
        while (i <= h && arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);

        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, h);
    }
}