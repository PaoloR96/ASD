#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int N, numBrani, Brani[MAX];
    Risultato R[MAX];
    int index = 0;
    int DP[MAX_N]; 
    
    while (index < 5) {
        //1.Inserimento dati di input
        if (scanf("%d", &N) == EOF) break; // Controllo fine file
        scanf("%d", &numBrani);
        
        //Inserisco le durate dei singoli brani
        for (int i = 0; i < numBrani; i++) scanf("%d", &Brani[i]);
        printf("\n");
        //2.Inizializzo DP
        InizializzaDP(DP, N); 
        //3.Calcolo DP
        int capResidua = CalcolaDP(DP, Brani, numBrani, N);
        //4. Trovo i valori associati al target
        R[index] = TrovaElementiInsieme(Brani, capResidua, numBrani);
        //passo al caso di test successivo
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) {
        StampaRisultati(R[i]);
    }
     
    system("pause");
    return 0;
}