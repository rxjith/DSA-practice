#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} node;

void unload(node *list);

int main(void){
    node *list = NULL;

    for (int i = 0; i < 3; i++){
        node *n = malloc(sizeof(node));
        
        if (n == NULL){
            printf("Memory allocation failed!\n");
            unload(list);
            return 1;
        }
        printf("Enter a number: "); scanf("%d", &n->number);
        n->next = NULL;

        // If list is empty:
        if (list == NULL){
            list = n;
        } 
        
        // If number belongs at the beginning of the list:
        else if (n->number < list->number){
            n->next = list;
            list = n;
        }
        
        // If number belongs later in the list:
        else{
            for (node *ptr = list; ptr != NULL; ptr = ptr->next){
                // If at the end of the list:
                if (ptr->next == NULL){
                    // Append mode:
                    ptr->next = n;
                    break;
                }

                // If in the middle of list:
                if (n->number < ptr->next->number){
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
        
    }

    // Printing numbers:
    for (node *ptr = list; ptr != NULL; ptr = ptr->next){
        printf("%d ", ptr->number);
    } printf("\n");

    // Freeing memory:
    unload(list);
    return 0;
}

void unload(node *list){
    node *ptr = list;
    while (ptr != NULL){
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}