// String reversal:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*, int);

int main(void) {

    // String declaration:
    char* string = malloc(100*sizeof(char));

    // Input: 
    printf("Enter a string: ");
    scanf(" %[^\n]", string);

    printf("Original String: %s\n", string);

    // Reversing func call:
    reverse(string, strlen(string));

    printf("Reversed String: %s\n", string);
    free(string);

    return 0;
}

void reverse(char* string, int n) {
    for (int i=0; i<n/2; i++) {
        char temp = *(string + n - 1 - i);
        *(string + n - 1 - i) = *(string + i);
        *(string + i) = temp;
    }
}