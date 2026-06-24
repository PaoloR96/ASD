#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    CasoTest ct;
    int N=0,index=0;
    int Risultato[100];
    scanf("%d",&N);
    for (int i = 0; i < N; i++){
        //1.Inserisco i dati per l'iesimo caso di test
        // Riempio tutte le classi previste per questo test case 
        scanf("%d %d", &ct.budget, &ct.num_classi);
        for (int j = 0; j < ct.num_classi; j++) {
            RiempiClasse(&ct, j);
        }
        //2.Inizializza DP
        InitDP(DP,ct.num_classi,ct.budget);
        //3.Calcola DP
        Risultato[i]=CalcolaSequenza(ct,DP);
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < N; i++){
        if (Risultato[i] != -1) {
            printf("%d\n", Risultato[i]);
        } else {
            printf("denaro insufficiente\n");
        }
        
    }
    system("pause");
    return 0;
}

/*
Complessità:O(NumClassi*Budget*NumeroProdotti)
Ricorrenza: Se la nuova spesa totale non supera il budget, segnala come possibile
                    if (b+prezzo_prodotto<=ct.budget){
                        DP[i+1][b+prezzo_prodotto]=1;
                    }
*/