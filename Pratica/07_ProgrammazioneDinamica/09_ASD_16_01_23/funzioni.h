#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdbool.h>
#include <limits.h>

/* definizione costanti */
#define SIZE 100
#define N 4
/*definizione variabile globale*/
extern bool dp[SIZE];
/* metodi */
int Somma(int M[], int dim);
void InitDp(bool dp[], int dim);
void PrintDp(bool dp[], int dim);
int CalcolaDp(bool dp[],int M[], int dim,int target);

#endif