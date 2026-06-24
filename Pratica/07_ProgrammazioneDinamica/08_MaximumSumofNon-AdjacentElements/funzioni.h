#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

/* definizione costanti */
#define N 4

/* definizione variabili globali */
extern int dp[N];

/* metodi */
void InitDp(int dp[N]);
int DpCalculate(int dp[N],int A[N]);
int max(int a,int b);

#endif