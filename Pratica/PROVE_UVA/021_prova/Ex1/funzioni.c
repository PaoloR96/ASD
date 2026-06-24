#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header

// Creazione nodo
struct Node *CreaNodo(int valore, char percorso[256]) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->valore = valore;
    strcpy(newNode->Percorso, percorso);
    newNode->assegnato = true;     
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserimento nodo con creazione dei rami mancanti
bool InserisciNodo(struct Node *Albero, struct Node *Nodo) {
    struct Node *NodoAttuale = Albero;

    // Naviga seguendo le 'L' e le 'R' della stringa s
    for (int i = 0; Nodo->Percorso[i] != '\0'; i++) {
        if (Nodo->Percorso[i] == 'L') {
            if (NodoAttuale->left == NULL) {
                // Crea un nodo di passaggio non ancora assegnato
                NodoAttuale->left = malloc(sizeof(struct Node));
                NodoAttuale->left->assegnato = false;
                NodoAttuale->left->left = NodoAttuale->left->right = NULL;
            }
            NodoAttuale = NodoAttuale->left;
        } 
        else if (Nodo->Percorso[i] == 'R') {
            if (NodoAttuale->right == NULL) {
                NodoAttuale->right = malloc(sizeof(struct Node));
                NodoAttuale->right->assegnato = false;
                NodoAttuale->right->left = NodoAttuale->right->right = NULL;
            }
            NodoAttuale = NodoAttuale->right;
        }
    }

    // Se arrivo a un nodo già assegnato, c'è un duplicato
    if (NodoAttuale->assegnato) return false;

    // Assegno il valore finale
    NodoAttuale->valore = Nodo->valore;
    NodoAttuale->assegnato = true;
    return true;
}


// Attraversamento per livello (Level-order traversa)
void StampaLevelOrder(struct Node *root) {
    if (root == NULL || !root->assegnato) {
        printf("not complete\n");
        return;
    }

    struct Node *coda[256];
    int testa = 0, coda_idx = 0;
    int risultati[256], r_idx = 0;

    coda[coda_idx++] = root;
    //Faccio scorrere la testa
    while (testa < coda_idx) {
        struct Node *attuale = coda[testa++];

        // Se un nodo non è assegnato, l'albero è incompleto
        if (!attuale->assegnato) {
            printf("not complete\n");
            return;
        }

        risultati[r_idx++] = attuale->valore;

        if (attuale->left) coda[coda_idx++] = attuale->left;
        if (attuale->right) coda[coda_idx++] = attuale->right;
    }

    // Stampa dei valori separati da spazio
    for (int i = 0; i < r_idx; i++) {
        printf("%d%c", risultati[i], (i == r_idx - 1) ? '\n' : ' ');
    }
}

// Funzione per ripulire la memoria per il prossimo caso di test 
void LiberaAlbero(struct Node *root) {
    if (root == NULL) return;
    LiberaAlbero(root->left);
    LiberaAlbero(root->right);
    free(root);
}