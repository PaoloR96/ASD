#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdio.h>
#include <string.h>

/* Definizione costanti basate sui limiti del problema */
#define MAX_C 21  // Massimo 20 capi + 1 
#define MAX_M 201 // Massimo 200 budget + 1 

typedef struct {
    int modello;      // Identificativo (es. 1 per camicie)
    int dati[20];     // Prezzi dei modelli (K max 20) 
    int size;         // Numero effettivo di modelli (K) 
} Capi;

/* Metodi */
void StampaInput(Capi A[], int numCapi);
void InitDP(int dp[MAX_C][MAX_M]);
int CalcoloDp(int dp[MAX_C][MAX_M], Capi A[], int numCapi, int budget);

#endif