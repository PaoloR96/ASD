#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>
#include <stdbool.h>

/* definizione costanti */
#define M 100

/* definizione variabili globali */
extern int dp[M];

/* metodi */
int SommaMonete(int monete[], int m);
void InitDp(int dp[],int n);
int CalcolaDp(int monete[],int dp[],int target,int m);

#endif