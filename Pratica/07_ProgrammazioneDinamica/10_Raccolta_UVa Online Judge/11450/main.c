#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int dp[MAX_C][MAX_M];
    int budget = 100;    // M 
    int numeroCapi = 4;  // C 

    // Definizione dei capi come da Sample Input 1 
    Capi A[] = {
        {1, {8, 6, 4}, 3},       
        {2, {5, 10}, 2},        
        {3, {1, 3, 3, 7}, 4},   
        {4, {50, 14, 23, 8}, 4}  
    };

    printf("SAMPLE INPUT:\n");
    StampaInput(A, numeroCapi);

    // Inizializzazione e Calcolo
    InitDP(dp);
    int val = CalcoloDp(dp, A, numeroCapi, budget);

    printf("\nSAMPLE OUTPUT:\n");
    if(val == -1) {
        printf("no solution\n"); // 
    } else {
        printf("%d\n", val);    
    }

    system("PAUSE");
    return 0;
}

