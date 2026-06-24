#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Node * CreateNode(int key){
        Node * node=malloc(sizeof(Node));
        node->key=key;
        node->left=node->right=node->p=NULL;
        return node;
}
void InsertNode(Node **tree,int key){
        //caso 0: Inserisco il nodo radice
        if(*tree==NULL){
           *tree=CreateNode(key);
            return;
        }
        //caso 1: Ora devo verificae se inserire il nodo nel sotto-albero di dx o sx in base al valore key
        //caso 1.a: Inserico il nodo nel sotto-albero di sx 
        if(key<(*tree)->key){
                if((*tree)->left==NULL){
                    //inserisco il nodo nel sotto-albero di sx
                    (*tree)->left = CreateNode(key);
                    //aggiorno p
                    (*tree)->left->p=*tree;
                }else{
                    //ho bisogno di un altra iterazione fintantochè non arrivo ad un nodo foglia per aggiungere 
                    //il nodo nel sotto-albero di sx
                    InsertNode(&(*tree)->left,key);
                }            
        //caso 2.a: Inserico il nodo nel sotto-albero di dx 
        }else{
             if((*tree)->right==NULL){
                    //inserisco il nodo nel sotto-albero di dx
                    (*tree)->right = CreateNode(key);
                    //aggiorno p
                    (*tree)->right->p=*tree;
                }else{
                    //ho bisogno di un altra iterazione fintantochè non arrivo ad un nodo foglia per aggiungere 
                    //il nodo nel sotto-albero di dx
                    InsertNode(&(*tree)->right,key);
                }           
        }        
}

void PrintTree(Node *tree) {
    if (tree != NULL) {
        PrintTree(tree->left);      //Visita ricorsivamente il sottoalbero sinistro
        printf("%d ", tree->key);    //Stampa il valore del nodo corrente
        PrintTree(tree->right);     //Visita ricorsivamente il sottoalbero destro
    }
}

Node *MaxNode(Node *tree) {
    // caso albero vuoto
    if (tree == NULL) return NULL;
    // caso base: nodo più a destra
    if (tree->right == NULL) return tree; // massimo trovato
    // ricorsione verso destra
    return MaxNode(tree->right);
}

Node *MinNode(Node *tree) {
    if (tree == NULL) return NULL;
    if (tree->left == NULL) return tree; // mainimo trovato
    return MinNode(tree->left);
}
Node *TreeSuccessor(Node *node) {
    if (node == NULL) return NULL;

    // Caso 1: sottoalbero destro presente
    if (node->right != NULL)
        return MinNode(node->right);

    // Caso 2: risalita ricorsiva ai genitori
    if (node->p == NULL)
        return NULL;  // radice → nessun successore

    if (node == node->p->left)
        return node->p;
    else
        return TreeSuccessor(node->p); // risali
}



void DeleteNode(Node **tree, int key) {
    // Caso base: se l'albero è vuoto, non c'è nulla da eliminare
    if (*tree == NULL) return;

    // Se la chiave da eliminare è minore della chiave del nodo corrente,
    // significa che il nodo da eliminare si trova nel sottoalbero sinistro.
    if (key < (*tree)->key) {
        DeleteNode(&((*tree)->left), key);
    } 

    // Se la chiave da eliminare è maggiore della chiave del nodo corrente,
    // significa che il nodo da eliminare si trova nel sottoalbero destro.
    else if (key > (*tree)->key) {
        DeleteNode(&((*tree)->right), key);
    } 

    // Se la chiave corrisponde, abbiamo trovato il nodo da eliminare.
    else {
        Node *temp = *tree;  // Salviamo il puntatore al nodo da rimuovere

        // ======================
        // CASO 1: Nodo foglia (nessun figlio)
        // ======================
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            *tree = NULL;     // Imposta il puntatore a NULL
        }

        // ======================
        // CASO 2a: Il nodo ha solo il figlio destro
        // ======================
        else if ((*tree)->left == NULL) {
            *tree = (*tree)->right;        // Sostituisce il nodo con il suo figlio destro
            if (*tree) (*tree)->p = temp->p; // Aggiorna il puntatore al padre
        }

        // ======================
        // CASO 2b: Il nodo ha solo il figlio sinistro
        // ======================
        else if ((*tree)->right == NULL) {
            *tree = (*tree)->left;         // Sostituisce il nodo con il suo figlio sinistro
            if (*tree) (*tree)->p = temp->p; // Aggiorna il puntatore al padre
        }

        // ======================
        // CASO 3: Il nodo ha due figli
        // ======================
        else {
            // Trova il nodo successore (il minimo nel sottoalbero destro)
            Node *successor = MinNode((*tree)->right);

            // Copia la chiave del successore nel nodo corrente
            (*tree)->key = successor->key;

            // Elimina ricorsivamente il successore (che sarà più semplice da rimuovere)
            DeleteNode(&((*tree)->right), successor->key);
        }
    }
}
