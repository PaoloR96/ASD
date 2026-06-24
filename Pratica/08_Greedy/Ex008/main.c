#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   
    //precaricamento elementi
    int B[] = {1, 1, 2, 2, 2, 3};
    int n = 6;
    //Ordinamento in modo crescente
    qsort(B,n,sizeof(int),Compara);
    //definisco il numero di occorrenze MAX
    int k=DefinisciOccorrenze(B,0,n-1);
    //Logica Greedy
    IncastraPila(B,n,k);


   

    system("pause");
    return 0;
}

/*Complessità:O(n*logn)*/