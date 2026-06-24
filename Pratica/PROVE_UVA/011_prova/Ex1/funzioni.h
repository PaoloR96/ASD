#ifndef FUNZIONI_H
#define FUNZIONI_H

#define N_MAX 100 // per comodità metto 100 anzichè 10000 
#define TEST_MAX 20

// Rappresenta un singolo legame nella lista di adiacenza
typedef struct Nodo {
    int amico;
    struct Nodo* next;
} Nodo;

typedef struct {
    int debito;      
    int visitato;   // Per segnare se abbiamo già calcolato questa persona
    Nodo* testa;     // Puntatore al primo amico della lista
} Persona;

// Questa struttura conterrà i dati di un singolo caso di test
typedef struct {
    int n; // numero amici
    int m; // numero amicizie
    Persona gruppo[N_MAX];
} CasoTest;
/*METODI*/
/*Metodi per gestire l'input e l'output*/
void RiempiCasiDiTest(CasoTest Test[],int dim);
void ElaboraCasiDiTest(CasoTest Test[],int dim);
/*Metodi per gestione DFS*/
Nodo * CreateNode(int id);
void aggiungi_amicizia(Persona gruppo[], int x, int y);
void dfs(int attuale, Persona gruppo[], int *bilancio_gruppo);

#endif
