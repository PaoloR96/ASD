#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Tree* T = CreateTree();
    int keys[] = {10, 20, 5, 15, 25, 2, 7, 12, 18, 22};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        Node* node = CreateNode(T, keys[i]);
        RbInsert(T, node);
    }

    printf("Stampa dell'albero in-order:\n");
    PrintTree(T, T->tree);  // stampa l'intero albero
    printf("\n");
    system("pause");
    return 0;
}
