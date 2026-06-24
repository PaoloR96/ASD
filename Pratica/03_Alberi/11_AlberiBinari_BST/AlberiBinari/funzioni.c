#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
Node * CreateNode(int key){
        Node * node=malloc(sizeof(Node));
        node->key=key;
        node->right=node->left=node->p=NULL;
        return node;
}
void InsertNode(Node **tree, int key) {
    // Definizione dei puntatori
    Node *current = *tree;
    Node *parent = NULL;
    // In questo ciclo mi muovo all'interno del BST
    // per capire se devo spostarmi a sx o dx in base al parametro key
    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // Creo il nuovo nodo che punta al parent
    Node *currentNode = CreateNode(key);
    currentNode->p = parent;

    // Caso 0: nodo radice (l'albero era vuoto)
    if (parent == NULL) {
        *tree = currentNode;
    }
    // Caso 1: il nuovo nodo va a sinistra
    else if (key < parent->key) {
        parent->left = currentNode;
    }
    // Caso 2: il nuovo nodo va a destra
    else {
        parent->right = currentNode;
    }
}

void PrintTree(Node *tree) {
    if (tree != NULL) {
        PrintTree(tree->left);              // visita il sottoalbero sinistro
        printf("%d ", tree->key);           // stampa il nodo corrente
        PrintTree(tree->right);             // visita il sottoalbero destro
    }
}
Node * MinTree(Node*tree){
     if (tree==NULL)return NULL;
     Node*min=tree;
     while (min->left!=NULL)min=min->left;
     return min;
}
Node * MaxTree(Node*tree){
     if (tree==NULL)return NULL;
     Node*max=tree;
     while (max->right!=NULL)max=max->right;
     return max;
}

Node * TreeSuccessor(Node *tree){
       
    if (tree == NULL) return NULL;
    Node *current = tree;

    // Caso 1: se esiste un sottoalbero destro,
    // il successore è il minimo del sottoalbero destro
    if(current->right!=NULL) return MinTree(current->right);

    // Caso 2: risali finché sei un figlio destro
     Node *parent = current->p;
    while (parent != NULL && current == parent->right) {
        current = parent;
        parent = parent->p;
    }

    return parent; // può essere NULL se non esiste successore
        
}   

void DeleteNode(Node** tree, int key) {
    Node* current = *tree;
    Node* parent = NULL;
    // CERCA il nodo da eliminare (tenendo traccia del padre)
    while (current != NULL && current->key != key) {
        parent = current;
        if (key < parent->key)
            current = current->left;
        else
            current = current->right;
    }

    // Caso 0: il nodo non è stato trovato
    if (current == NULL)return;

    // Caso 1: il nodo non ha figli (è una foglia)
    if (current->left == NULL && current->right == NULL) {
        // Se il nodo è la radice
        if (parent == NULL) {
            *tree = NULL;
        }
        // Se è figlio sinistro
        else if (parent->left == current) {
            parent->left = NULL;
        }
        // Se è figlio destro
        else {
            parent->right = NULL;
        }
    }

    // Caso 2: il nodo ha un solo figlio
    else if (current->left == NULL || current->right == NULL) {
        Node* child;

        // Determina quale figlio esiste
        if (current->left != NULL)
            child = current->left;
        else
            child = current->right;

        // Se il nodo da eliminare è la radice
        if (parent == NULL) {
            *tree = child;
        }
        // Se è figlio sinistro
        else if (parent->left == current) {
            parent->left = child;
        }
        // Se è figlio destro
        else {
            parent->right = child;
        }

        // Aggiorna il puntatore al padre del figlio
        child->p = parent;
    }

    // Caso 3: il nodo ha due figli
    else {
        // Trova il successore (il minimo del sottoalbero destro)
        Node* successor = MinTree(current->right);

        // Copia il valore del successore nel nodo corrente
        current->key = successor->key;

        // Elimina il successore (che sarà un caso più semplice)
        DeleteNode(&(current->right), successor->key);
    }
}

Node * SearchNode(Node **tree,int key){
        Node*current= * tree;
        //Controlla se l’albero è vuoto
        if(current==NULL || current->key==key) return current;
         // la ricerca continua ricorsivamente nel sottoalbero sinistro
        if(key<current->key) 
            return SearchNode(&(current->left),key);
         // la ricerca continua ricorsivamente nel sottoalbero destro
        else 
            return SearchNode(&(current->right),key);

}
