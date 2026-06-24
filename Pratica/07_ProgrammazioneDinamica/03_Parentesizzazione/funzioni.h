#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>  // per INT_MAX

// Costanti
#define N 10


// Variabili globali
extern int DP[N][N];         // DP[i][j]
extern int S[N][N];
// Funzioni
void InizializzaDp(int DP[N][N], int n);
void stampaDP(int DP[N][N], int n);
void stampaParentesi(int S[N][N], int i, int j);
void matrixChain(int C[], int n);

#endif