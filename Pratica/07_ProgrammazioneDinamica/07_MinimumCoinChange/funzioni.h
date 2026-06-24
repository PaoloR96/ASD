#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

/* definizione costanti */
#define N 3   // numero di monete
#define C 6   // somma target

/* definizione variabili globali */
extern int dp[2*C + 1];  // dimensione sufficiente per il DP

/* metodi */
void InitDp(int dp[2*C + 1]);
int DpMinimumCoin(int dp[2*C + 1], int coins[N]);
int min(int a, int b);  // serve min, non max

#endif