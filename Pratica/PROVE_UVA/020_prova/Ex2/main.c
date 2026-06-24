#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Grafo  G[MAX];
    int m=0; //rappresenta il numero di grafi
    int index=0;
    printf("SAMPLE INPUT:\n");
    scanf("%d",&m);
    while (index<m){
        //1.Inserimento dati
        InserisciDati(&G[index]);
        //passo al caso di test successivo
        index++;
    }
    index=0;
    printf("SAMPLE OUTPUT:\n");
    while (index<m){
        //1.Inizializzo le variabili globali
        Max=0;
        memset(SoluzioneOttima, 0, sizeof(SoluzioneOttima));
        memset(Colorato, 0, sizeof(Colorato)); 
        //2.Calcolo sequenza
        ColoraGrafo(1,&G[index]);
        //3.Stampa risultato
        printf("%d \n",Max);
        // Seconda riga: lista dei nodi neri separati da spazio 
        int primo = 1;
        for (int i = 1; i <= G[index].n; i++) {
            if (SoluzioneOttima[i] == 1) {
                if (!primo) printf(" ");
                printf("%d", i);
                primo = 0;
            }
        }
    
        printf("\n");
        //passo al caso di test successivo
        index++;
    }
    
    system("pause");
    return 0;
}
/*Complessità:O(2^N)*/