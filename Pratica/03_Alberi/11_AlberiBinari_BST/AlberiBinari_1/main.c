#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    Node *tree = NULL;
    srand(time(NULL));  // Inizializza il generatore di numeri casuali
    int A[10] = {37, 35, 64, 10, 54, 88, 28, 72, 34, 66};
    for (int i = 0; i < 10; i++) InsertNode(&tree, A[i]);
    printf("Albero BST (struttura):\n");
    PrintTree(tree);
    printf("\n");
    printf("\n");
    Node *min = MinNode(tree);
    printf("Albero BST-MIN: %d\n",min ->key);
    printf("\n");
    Node *max = MaxNode(tree);
    printf("Albero BST-MAX: %d\n",max->key);
    printf("\n");
    Node *nodeSuccessor = TreeSuccessor(tree);
    printf("\n");
    if (nodeSuccessor != NULL) {
        printf("Albero BST - SUCCESSOR:\n");
        printf("  Nodo corrente: %d\n", tree->key);
        printf("  Successore: %d\n", nodeSuccessor->key);
        printf("  Indirizzo successore: %p\n", (void*)nodeSuccessor);
        printf("  left: %p\n", (void*)nodeSuccessor->left);
        printf("  right: %p\n", (void*)nodeSuccessor->right);
    } else {
        printf("Il nodo con chiave %d non ha un successore (è il massimo del BST).\n", tree->key);
    }
    printf("\n");
    DeleteNode(&tree, 64);  // elimino il nodo 64
    printf("\nDopo eliminazione del nodo 64:\n");
    printf("\n");
    PrintTree(tree);
    printf("\n");
    printf("\n");
    system("pause");
   
    return 0;
}
