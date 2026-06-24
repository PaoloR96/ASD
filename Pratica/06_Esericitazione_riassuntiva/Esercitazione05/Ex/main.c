#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int k = 0, d = 0, index = 0, stato = 1;
    printf("Definisci k=numero di sequenze & d=dimensione di ogni sequenza:");
    scanf("%d,%d",&k,&d);
    printf("\n");
    char Seq[2*k][d];  // array per tutte le sequenze
    printf("SAMPLE INPUT:\n");

    while (stato != 0 && index < 2*k) {
        printf("Inserisci %d sequenza (%d caratteri):\n", index+1, d);
        stato = RiempiSequenza(Seq[index], d);
        if(stato != 0) index++;
    }

    printf("SAMPLE OUTPUT:\n");
    //uso index/2 per processare tutte le coppie complete
    for (int i = 0; i < index/2; i++)TrovaMassimo(Seq[2*i], Seq[2*i+1], d);
    

    system("pause");
    return 0;
}

/*
La complessità in questo caso, essendo basata sul backtracking, è O(k ⋅ 2^d).
 *k rappresenta il numero di coppie di sequenze che dobbiamo analizzare;
 *d è la lunghezza delle sequenze stesse. 
 Per ciascuna coppia, il backtracking esplora tutti i possibili rami di scelta dei caratteri, generando quindi fino a 2^d combinazioni. 
 Di conseguenza, la complessità cresce esponenzialmente con d e linearmente con k.

Per sequenze lunghe e un numero elevato di coppie, sarebbe più conveniente utilizzare la programmazione dinamica (DP), 
che permette di gestire valori grandi di d e k in modo efficiente. 
Tuttavia, in questo esercizio utilizzo il backtracking principalmente a scopo didattico, 
per esercitarmi con la ricorsione e la gestione dei rami.

*/