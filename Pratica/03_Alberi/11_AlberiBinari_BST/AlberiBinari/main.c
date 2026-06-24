#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Node *tree = NULL;
    srand(time(NULL));  // Inizializza il generatore di numeri casuali
    int A[10] = {37, 35, 64, 10, 54, 88, 28, 72, 34, 66};
    for (int i = 0; i < 10; i++) InsertNode(&tree, A[i]);
    printf("\n");
    printf("Albero BST (struttura):\n");
    PrintTree(tree);
    printf("\n");
    printf("\n");
    Node *minNode = MinTree(tree);
    printf("Albero BST-MIN: %d\n",minNode ->key);
    printf("\n");
    Node *maxNode = MaxTree(tree);
    printf("Albero BST-MAX: %d\n",maxNode->key);

    printf("\n");
    Node *nodeSuccessor = TreeSuccessor(tree);
    printf("\n");
    if (nodeSuccessor != NULL) {
            printf("Albero BST-SUCCESSOR:\n");
            printf("  key: %d\n", nodeSuccessor->key);
            printf("  left: %p\n", (void*)nodeSuccessor->left);
            printf("  right: %p\n", (void*)nodeSuccessor->right);
    } else {
            printf("Il nodo selezionato non ha un successore (è il massimo del BST).\n");
    }
    printf("\n");
    DeleteNode(&tree, 64);  // elimino il nodo 64
    printf("\nDopo eliminazione del nodo 64:\n");
    PrintTree(tree);
    printf("\n");
    Node *found=SearchNode(&tree,64);
    printf("\n");
    if(found!=NULL)printf("il numero e' presente!");
    printf("\n");
    if(found==NULL)printf("il numero non e' presente!");
    printf("\n");
    system("pause");
    return 0;

}
