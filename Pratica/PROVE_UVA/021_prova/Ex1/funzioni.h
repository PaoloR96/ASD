#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdbool.h>

#define MAX_NODI 256

struct Node {
    int valore;
    bool assegnato;
    char Percorso[256];
    struct Node *left;
    struct Node *right;
};

struct Node *CreaNodo(int valore, char percorso[256]);
bool InserisciNodo(struct Node *Albero, struct Node *Nodo);
void StampaLevelOrder(struct Node *root);
void LiberaAlbero(struct Node *root);
#endif