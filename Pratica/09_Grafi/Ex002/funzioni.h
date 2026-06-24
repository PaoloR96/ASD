#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX 26 // I nodi vanno da 'A' a 'Z' 

/* Struttura per rappresentare un vicino nella lista di adiacenza */
typedef struct Nodo {
    int v_indice;           // L'indice del nodo vicino (0-25)
    struct Nodo* next;      // Puntatore al prossimo vicino
} Nodo;

/* Struttura per gestire la testa della lista di ogni nodo */
typedef struct {
    Nodo* testa;
} Arco;

/* Struttura per un singolo caso di test */
typedef struct {
    char c;                 // Il carattere del nodo massimo 
    Arco arco[MAX];         // Array di liste di adiacenza
    int visitato[MAX];      // Array per segnare i nodi visitati
} CasoTest;

/* Metodi */
int charToIndex(char c);
void RiempiCasoDiTest(CasoTest test[], int dim);
void ElaboraCasiDiTest(CasoTest test[], int dim);

/* Metodi per gestire il grafo */
Nodo * CreaNodo(int v);
void AggiungiCollegamento(Arco arco[], int u, int v);
void dfs(int attuale, Arco arco[], int visitato[]);

#endif