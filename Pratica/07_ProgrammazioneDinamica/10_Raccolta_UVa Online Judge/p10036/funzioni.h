#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

/* definizione costanti */
#define DIM_N 1000
#define DIM_K 100

/* definizione variabili globali */
extern int dp[DIM_N][DIM_K];

/* metodi */
void InitDp(int dp[DIM_N][DIM_K],int K, int N);
void CalcolaDp(int dp[DIM_N][DIM_K],int C[],int K, int N);

#endif