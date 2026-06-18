#include <stdio.h>
int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    printf("%d\n", *arr);
    arr++;
    printf("%d\n", *arr);
    return 0;
}