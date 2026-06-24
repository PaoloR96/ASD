#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int T; // Numero di casi di test
    int index=0;
    if (scanf("%d", &T) != 1) return 0;
    // Array di supporto per la mappatura (allocato una sola volta per efficienza)
    int mappa_colori[MAX_N];
    int Risultato[MAX_N];
    while (index<T){
        int N, M, L;
        scanf("%d %d %d", &N, &M, &L);
        // Chiamata al primo metodo: riempie la mappa
        inserimento_liste(mappa_colori, M);
        // Chiamata al secondo metodo: calcola il risultato
        Risultato[index] = calcola_segmenti(mappa_colori, L);
        //passo al prossimo caso di test
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d \n",Risultato[i]);
    

   

    system("pause");
    return 0;
}
/*
Complessità:O(N+L) dove   O(N) deriva dall'operazione di inserimento
                   mentre O(L) deriva dall'operazione calcola_segmenti

*/