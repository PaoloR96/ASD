#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>  // per INT_MAX

// Costanti
#define MAX 1000
#define N 4
#define MaxLen 10
#define PageWidth 10

// Variabili globali
extern int lengths[N];      // lunghezze parole
extern int Bandness[N][N];  // tabella badness
extern int DP[N+1];         // DP[i] = costo minimo da parola i in poi
extern int bestSplit[N];    // bestSplit[i] = indice j scelto per riga

// Funzioni
void printWordsInline(char words[][MaxLen], int n);
void calculateLengths(char words[][MaxLen], int n, int lengths[]);
void CalcolaBandness(int Bandness[N][N], int lengths[], int n);
void stampaBandness(int Bandness[N][N], int n);
int computeDP(int i, int n);
void stampaRigheOttimali(char words[][MaxLen], int n);

#endif