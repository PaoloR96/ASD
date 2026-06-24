#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Node *LinkedList=NULL;
    int val = 0;
    InsertNode(&LinkedList, 5);
    InsertNode(&LinkedList, 10);
    InsertNode(&LinkedList, 15);
    PrintList(LinkedList); // Output: 5 -> 10 -> 15 -> NULL
    DeleteNode(&LinkedList, 10);
    PrintList(LinkedList); // Output: 5 -> 15 -> NULL
    val=SearchNode(&LinkedList, 10);
    if(val==1){
        printf("Il valore 10 e'stato trovato!");
    }else{
        printf("Il valore 10 non e'stato trovato!");
    }
    printf("\n");
    system("pause");
    return 0;
}
