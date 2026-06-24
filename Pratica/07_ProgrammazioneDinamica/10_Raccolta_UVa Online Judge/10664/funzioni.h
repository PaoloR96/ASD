#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

/* definizione costanti */
#define MAX_N 20 //numero massimo di valigie
#define WEIGHT_N 200 //peso massimo
#define TEST_CASES 5

typedef struct {
    int n;                // numero di valigie
    int weights[MAX_N];   // pesi
} TestCase;


/* metodi */
void StampaCasiTest(TestCase tests[TEST_CASES],int dimTest);
int Somma(int A[MAX_N],int dim);
void InitDp(int dp[MAX_N][WEIGHT_N],int numValigie,int target);
int  CalcolaDp(int dp[MAX_N][WEIGHT_N],int W[MAX_N],int numValigie,int target);


#endif