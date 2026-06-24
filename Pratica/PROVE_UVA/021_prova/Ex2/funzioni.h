#ifndef FUNZIONI_H
#define FUNZIONI_H

// Costanti basate sui vincoli del problema
#define MAX_T 80   // Numero massimo di test case (T < 80) 
#define MAX 201     // Numero massimo di incroci (v <= 200) 
#define MAX_E 10001 // Numero massimo di strade (e <= 10000) 

typedef struct {
    int f; // partenza
    int t; //arrivo
} Strada;

typedef struct {
    int v; //numero di incroci
    int e; //numero di strade
    Strada Mappa[MAX]; //mappa che indica la presenza di una strada tra f e t.

}CasoTest;


/* Variabili globali */
extern int PosizionaGuardia[MAX]; // 1 se c'è una guardia, 0 altrimenti
extern int min;                  // Numero minimo di guardie trovato
extern int trovato_valido;       // Flag (1 se esiste almeno una soluzione valida, 0 altrimenti)

/* Metodi */
void RiempiCasoTest(Strada Mappa[], int dim_e);
void Risolvi(int incrocio_attuale, Strada Mappa[], int num_strade, int num_incroci);
int CeckCopertura(Strada Mappa[], int num_strade);
int ControllaIncrocio(int incrocio_attuale, Strada Mappa[], int num_strade);

#endif