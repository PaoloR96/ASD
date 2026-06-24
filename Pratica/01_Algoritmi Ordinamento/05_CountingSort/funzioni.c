#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void GeneraNumeri(int A[], int size,int k) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % k;
    }
}
void CountingSort(int A[],int B[],int size,int k){
        int C[k];
        //inizializzo il vettore delle occorenze
        for(int i=0;i<k;i++)C[i]=0;
        //calcolo delle occorrenze
         for (int j = 0; j < size; j++)C[A[j]]++;
        printf("Vettore delle occorrenze C: ");
        StampaArray(C, k);
        //calcolo cumulativo delle occorenze
         for (int j = 1; j <k; j++)C[j]=C[j]+C[j-1];
        printf("Vettore delle occorrenze cumulative C: ");
        StampaArray(C, k);
       for (int j = size - 1; j >= 0; j--){
            B[C[A[j]] - 1] = A[j];
            C[A[j]]--;
        }
    }