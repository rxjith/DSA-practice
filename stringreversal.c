/* String reversal using the two-pointer technique 
   (well, basically one and an arithmetically calculated enemy pointer) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype:
void reverse(char*, int);

int main(void) {

    // String allocation of size = 100:
    char* string = malloc(100*sizeof(char));

    // User-input: 
    printf("Enter a string: ");
    scanf(" %[^\n]", string);

    printf("Original String: %s\n", string);            // Printing original string

    // Function call:
    reverse(string, strlen(string));

    printf("Reversed String: %s\n", string);            // Printing reversed string
    free(string);                                       // Freeing memory

    return 0;
}

void reverse(char* string, int n) {
    for (int i=0; i<n/2; i++) {                         /* Loops over half the string, 
                                                           retreives the other half using some basic arithmetic */
        char temp = *(string + n - 1 - i);              // Storing (n - 1 - i)th element in temp
        *(string + n - 1 - i) = *(string + i);          // Storing ith element in (n - 1 - i)th position
        *(string + i) = temp;                           // Storing temp into ith position
        
    }
}