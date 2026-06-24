#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    int A[10],N=0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("Inserisci Vettore:");
    InsNumeri(A, size);
    //printf("Stampa Vettore:");
    //StampaArray(A, size);
    ContaUno(A,size);
   

    system("pause");
    return 0;
}
/*

Complessità è T(n)=O(logn),in quanto la funzione ricorsiva "PrimoUno" 
applica un approccio analogo alla ricerca binaria

*/