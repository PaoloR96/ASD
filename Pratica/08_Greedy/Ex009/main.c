#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    //1.Definisco il caso di test
    CasoTest C;
    //Precarico i valori
    C.n=2; //numero di teste del drago
    C.m=3;//numero di cavalieri nel regno
    //diametro delle teste del drago in cm
    C.N[0] = 5;
    C.N[1] = 4;
    //altezza dei cavalieri di Loowater, anch'essa in cm
    C.M[0] = 7;
    C.M[1] = 8;
    C.M[2] = 4;
    //2.Stampa Input
    printf("SAMPLE INPUT:\n");
    printf("%d %d \n",C.n,C.m);
    StampaCasiTest(C.N,C.n);
    StampaCasiTest(C.M,C.m);
    //3.Passo necessario ordino in modo crescente Teste e Cavalieri
    qsort(C.N,C.n,sizeof(int),Compara);
    qsort(C.M,C.m,sizeof(int),Compara);
    //4.Logica Greedy
    printf("\n");
    printf("SAMPLE OUTPUT:\n");
    CalcolaSequenza(C);

    

   

    system("pause");
    return 0;
}

/*Complessità totale:O(nlogn+mlogm), dovuto al fatto che ordino i due vettori per poi processarli */