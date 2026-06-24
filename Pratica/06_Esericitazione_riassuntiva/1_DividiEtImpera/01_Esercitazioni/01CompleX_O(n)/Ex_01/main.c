#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {


    int A[10]={4,3,-2,-1,0,0,1,-1,2,-3};
    
    printf("Stampa vettore:");
    StampaArray(A, 10);
    printf("\n");
    TrovaPositivi(A,10);
    printf("\n");
    system("pause");
    return 0;
}
/*
La funzione ContaPositivi(A, start, end):

1)Se l’intervallo ha un solo elemento, lo controlla: questo è un passo O(1).

2)Altrimenti, divide l’array in due metà: [start, mid] e [mid+1, end].

3)Chiama ricorsivamente se stessa sulle due metà.

4)Somma i risultati delle due metà: anche questo è un passo O(1).

Quindi:T(n)=2⋅T(n/2)+O(1)

2⋅T(n/2)  ->due chiamate ricorsive sulle metà

O(1) → controllo e somma

Quindi la complessità è O(n)

Posso risolverlo anche con il metodo dell'esperto,dove:
*Numero di sottoproblemi: a=2
*Fattore di divisione: b=2
*Contributo non ricorsivo: f(n)=O(1)
Quindi:T(n)=O(n^log2^​2)=O(n^1)=O(n)

*/