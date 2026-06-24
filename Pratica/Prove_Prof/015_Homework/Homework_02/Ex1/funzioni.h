#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct Node{
    /* data */
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

/*Metodi*/
Node * CreateNode(int key);
Node* CreaListaNodi(int A[],int dim);
void StampaLista(Node *ListaNodi);
void InvertiLista(Node *ListaNodi);
#endif
