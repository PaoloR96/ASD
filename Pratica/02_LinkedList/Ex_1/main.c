#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    Node *LinkedList=NULL;
    int val = 0;
    srand(time(NULL));  // Inizializza il generatore di numeri casuali
    for (int i = 0; i < 10; i++) InsertNode(&LinkedList, rand() % 101);
    PrintList(LinkedList);
    printf("\n");
    SwapNode(&LinkedList);
    PrintList(LinkedList);
    system("pause");
    
    return 0;
}
