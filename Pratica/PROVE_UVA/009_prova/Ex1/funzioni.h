#ifndef FUNZIONI_H
#define FUNZIONI_H


#define MAX_NODI 256   // Massimo numero di nodi per albero
#define MAX_STR 64     // Lunghezza massima della stringa in un nodo

// Definizione della struct Nodo
typedef struct {
    int n;             // Valore numerico del nodo
    char s[MAX_STR];   // Stringa associata al nodo
    int lunghezza; //dimensione stringa iesima 
} Nodo;
/*Metodi*/
void stampaAlbero(Nodo array[], int count);
void DefinisciLunghezzaNodi(Nodo N[],int dim);
int compareLivello(const void* a, const void* b);
int IsCompleto(Nodo N[],int dim);


#endif
