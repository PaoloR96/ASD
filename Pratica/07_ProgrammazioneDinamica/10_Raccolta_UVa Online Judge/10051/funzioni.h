#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdio.h>
#include <string.h>

/* Definizione costanti basate sui limiti del problema */
#define N 501 
#define C 6

typedef struct {
    int id;             // Identificativo cubo
    int color[C];      // Un cubo è descritto indicando i colori delle sue facce nel seguente ordine:front, back, left,right, top e bottom
} Cubo;

typedef struct {
    int cubo;   // Indice del cubo precedente (j)
    int faccia; // Indice della faccia superiore del cubo precedente (f_prev)
} Parent;

/* Metodi */
void StampaInput(Cubo A[], int numCubi);
void InitDP(int dp[N][C],Parent parent[N][C],int numCubi);
int CalcolaDP(int dp[N][C],Parent parent[N][C],Cubo A[],int numCubi,int *bestI, int *bestF);
void stampaTorre(Parent parent[N][C], int i, int f);

#endif