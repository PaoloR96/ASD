#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
extern int MinimoGlobale;

int main() {
    
    CasoTest T[TEST];
    
    int index=0,numTest=0;
    printf("SAMPLE INPUT:\n");
    scanf("%d",&numTest);
    while (index!=numTest){
        RiempiCasiTest(T[index].S);
        index++;
    }
    
    index = 0;
    printf("SAMPLE OUTPUT:\n");
    while (index != numTest) {
        // 1. Reset del minimo per il nuovo caso
        MinimoGlobale = 8; 
        int posizioneRegina[R] = {0}; 
        // 2. Avvio del backtracking
        PosizioneRegina(T[index].S, posizioneRegina, 0);
        // 3. Stampa del risultato nel formato richiesto
        printf("Case %d: %d\n", index + 1, MinimoGlobale);
        index++;
    }

    system("pause");
    return 0;
}
/*O(N!)*/