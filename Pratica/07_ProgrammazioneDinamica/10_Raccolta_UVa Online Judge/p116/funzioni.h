#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

/* definizione costanti */
#define N 10
#define M 100

/* definizione variabili globali */
extern int dp[N][M];
extern int parent[N][M];

/* metodi */
void InitDp(int dp[N][M],int parent[N][M],int righe,int colonne);
void CalcolaDP(int dp[N][M],int parent[N][M],int matrice[][6],int righe,int colonne);
int Minimo(int a, int b, int c);
int confronta(const void *a, const void *b);


#endif