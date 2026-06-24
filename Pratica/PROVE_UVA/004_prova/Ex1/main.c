#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int vettore[5] = {9,1,0,5, 4};
    int n=sizeof(vettore)/sizeof(vettore[0]);
    int risultato=Merge(vettore, 0,n-1);
    printf("%d",risultato);

   

    system("pause");
    return 0;
}
/*Complessità:O(n*logn)*/