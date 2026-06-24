#ifndef FUNZIONI_H
#define FUNZIONI_H
#define NODI    200
/* Struttura per rappresentare un vicino nella lista di adiacenza */
typedef struct Nodo{
    /* data */
    int v_indice;   // L'indice del nodo vicino
    struct Nodo* next;// Puntatore al prossimo vicino
}Nodo;
/* Struttura per gestire la testa della lista di ogni nodo */
typedef struct {
    Nodo* testa;
} Arco;

typedef struct {
        int l;  //numero di archi
        int n; //numero nodi differenti
        Arco arco[NODI];
        int colore[NODI];  //per gestire lo stato della BFS (fondamentale per distinguere tra non visitato, colore 1 e colore 2).
}CasoDiTest;
/*metodi per creare e collegare i nodi di un arco*/
Nodo * CreateNodo(int n1);
void CollegaNodi(Arco arco[],int n1,int n2);
/*metodi per gestire i casi di test*/
void RiempiCasoTest(CasoDiTest *test,int dim);
void ElaboraCasi(CasoDiTest test[], int numCasi);
/*metodi per gestire la coda*/
void Enqueue(int coda[], int *tail, int nodo);
int Dequeue(int coda[], int *head);
/*metoto per gestire la bfs*/
void BfsCasoTestx(Arco arco[],int colore[],int l,int n);
#endif
