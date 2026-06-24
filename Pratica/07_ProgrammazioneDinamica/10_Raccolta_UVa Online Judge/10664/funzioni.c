#include <stdio.h>
#include "funzioni.h"
void StampaCasiTest(TestCase tests[TEST_CASES],int dimTest){
    for (int i = 0; i < dimTest; i++) {
            printf("Test %d: ", i + 1);
            for (int j = 0; j < tests[i].n; j++) {
                printf("%d ", tests[i].weights[j]);
            }
            printf("\n");
        }
}
int Somma(int A[MAX_N], int dim) {
    int somma = 0;   
    for (int i = 0; i < dim; i++)somma += A[i];
    return somma;
}

void InitDp(int dp[MAX_N+1][WEIGHT_N],int numValigie,int target) {
    for (int i = 0; i <= numValigie; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = 0;
        }
    }
}

int  CalcolaDp(int dp[MAX_N][WEIGHT_N],int W[MAX_N],int numValigie,int target){
    //// Caso base: peso 0 con 0 valigie è possibile
    dp[0][0]=1;
    //Ricorrenza
    for (int i = 1; i <= numValigie; i++) {
        int pesoAttuale = W[i-1]; // Prendo il peso della valigia corrente
        for (int j = 0; j <= target; j++) {
            // Opzione 1: Non prendo la valigia i-esima (eredito lo stato precedente)
            dp[i][j] = dp[i-1][j];
            // Opzione 2: Prendo la valigia i-esima (se il peso ci sta nel target)
            if (j >= pesoAttuale && dp[i-1][j - pesoAttuale] == 1) dp[i][j] = 1;
        }
    }
    return dp[numValigie][target];        
}


