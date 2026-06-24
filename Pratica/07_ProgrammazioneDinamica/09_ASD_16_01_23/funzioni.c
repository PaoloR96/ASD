#include <stdio.h>
#include "funzioni.h"

int Somma(int M[], int dim) {
    int somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += M[i];
    }
    return somma;
}

void InitDp(bool dp[], int dim) {
    for (int i = 0; i < dim; i++) dp[i] = false;
}

void PrintDp(bool dp[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}

int CalcolaDp(bool dp[],int M[], int dim,int target){
    /*caso base:*/
    dp[0]=true;
    /*ricorrenza per la costruzione di dp[i] */
    for (int moneta= 0; moneta <dim ; moneta++){
        int c=M[moneta];
        for (int x= target; x>=c; x--) dp[x] = dp[x] || dp[x - c];  
    }
    /* trova la somma massima raggiungibile ≤ target */
    for (int i = target; i >= 0; i--) {
        if (dp[i] == true) {
            return i;
        }
    }

    return 0;
}