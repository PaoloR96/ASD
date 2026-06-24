#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*Definizione Nodo*/
typedef  struct  Nodo{
    /* data */
    int key;
    struct Nodo * left;
    struct Nodo * right;
}Nodo;
/*Prototipi*/
/*Metodi per gestire i casi di test*/
void CreazioneAlbero(int V[],int dim);
void StampaVettore(int V[],int dim);
/*Metodi per gestire l'albero*/
Nodo *CreateNodo(int value);
Nodo * InsertNodo(Nodo *T, Nodo *z);
void InorderTreeWalk(Nodo *x);
#endif
