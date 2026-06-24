#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoDiTest test[MAX];
    int count = 0;
    // ===== 1. INPUT =====
     printf("Sample Input: \n");
    while(1) {
        scanf("%d %d", &test[count].N1, &test[count].N2);
        //definisco le dimensioni delle due torri
        if(test[count].N1 == 0 && test[count].N2 == 0)break;
        //inserimento torre1
        for(int i = 0; i < test[count].N1; i++)scanf("%d", &test[count].torre1[i]);
        //inserimento torre2
        for(int i = 0; i < test[count].N2; i++)scanf("%d", &test[count].torre2[i]);

        // ===== 2. CALCOLO =====
        int DP[MAX][MAX];
        CalcolaDP(DP,test[count].torre1, test[count].N1,test[count].torre2, test[count].N2);
        //Aggiorno il risultato
        test[count].risultato = DP[test[count].N1][test[count].N2];
        count++;
    }

    // ===== 3. OUTPUT =====
    printf("SampleOutput \n");
    for(int i = 0; i < count; i++) {
        printf("TwinTowers#%d \n", i + 1);
        printf("NumberofTiles: %d \n", test[i].risultato);
    }

    system("pause");
    return 0;
}