#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100

typedef struct {
    int start;
    int end;
} Intervallo;

typedef struct {
    Intervallo Window;
    int numeroEventi;
} Risultato;


/* Metodi */
Risultato RicercaBinaria(int Tempo[MAX],int dim,Intervallo Window);
Risultato TrovaMassimo(int Tempo[MAX], int dim, int Y);

#endif
