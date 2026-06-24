#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void Merge(int A[MAX],int p, int r){
    if(p<r){
        //calcolo il punto medio
       int q = p + (r - p) / 2;
        Merge(A,p,q);//Ricorsione sulla sotto-sequenza di sx
        Merge(A,q+1,r);//Ricorsione sulla sotto-sequenza di dx
        //unisco le due sotto-sequenza in una sola ordinata
        MergeSort(A,p,q,r);
    }
}
// unisco le due sotto-sequenza in una sola ordinata
void MergeSort(int A[], int p, int q, int r) {
    // calcolo le dim dei due sotto-vettori L ed R
    int n1 = q - p + 1;
    int n2 = r - q;
    // inizializzo L ed R
    int L[n1 + 1], R[n2 + 1];
    // 1.Riempio i due vettori
    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    for (int j = 0; j < n2; j++) R[j] = A[q + j + 1];
    // 1.A Inizializzo le sentinelle
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    // 2.Fusione dei vettori L ed R
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        // Confronto gli elementi dei due sotto-vettori
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


void StampaSeq(int A[MAX],int dim){
    for (int i = 0; i < dim; i++)printf("%d ",A[i]);
    printf("\n");
}