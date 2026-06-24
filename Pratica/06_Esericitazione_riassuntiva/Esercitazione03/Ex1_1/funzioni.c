#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#include <limits.h>

int mediana = INT_MAX;

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void CalcolaMediana(int A[], int r, int start, int end, int num) {

    /* caso base: esco dalla ricorsione */
    if (num > end) return;

    /* caso ricorsivo */
    int medianaTMP = SommaParziale(A, num, r);

    /* trovo il valore minimo */
    if (medianaTMP < mediana)
        mediana = medianaTMP;

    /* passo al numero successivo */
    CalcolaMediana(A, r, start, end, num + 1);
}

int SommaParziale(int A[], int num, int r) {
    int sommaparz = 0;
    int diffparz  = 0;

    for (int i = 0; i < r; i++) {
        if (A[i] > num)
            diffparz = A[i] - num;
        else
            diffparz = num - A[i];

        sommaparz += diffparz;
    }

    return sommaparz;
}

void CalcolaDistanzaOttimale(int A[], int r) {

    mediana = INT_MAX; 
    CalcolaMediana(A, r, A[0], A[r-1], A[0]);
    printf("%d",mediana);
}

/*Complessità :T(N)=O(r)×K=O(r⋅(end−start+1))

r=elementi dell'insieme
SommaParziale(A, num, r)---> O(r)
CalcolaMediana(A, r, start, end, num + 1); ---> ricorsione su (end - start + 1) valori

*/