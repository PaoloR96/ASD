#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Node* lista = NULL;

    InsertNode(&lista, 30);
    InsertNode(&lista, 20);
    InsertNode(&lista, 10);

    PrintListForward(lista);
    printf("\n");
    PrintListBack(lista);
    printf("\n");

    
    DeleteNode(&lista, 20);
    printf("\n");
    PrintListForward(lista);
    printf("\n");
    PrintListBack(lista);
    printf("\n");

   
    system("pause");
    return 0;
}
