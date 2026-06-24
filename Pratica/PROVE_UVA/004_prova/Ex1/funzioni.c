#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int Merge(int A[],int p,int r){
    int inversioniTotali = 0;
    if(p<r){
        int q=(p+r)/2;
        inversioniTotali+=Merge(A,p,q);//inverione a sx
        inversioniTotali+=Merge(A,q+1,r);//inverione a dx
        inversioniTotali+=ContaInversioni(A,p,q,r);//Conta le inversioni "miste", ovvero quelle in cui un elemento della metà sinistra è maggiore di un elemento della metà destra.
    }
    return inversioniTotali;
}

int ContaInversioni(int A[],int p,int q,int r){
        int inversioni=0;
        int n1=q-p+1;
        int n2=r-q;
        int L[n1],R[n2];
        // Copia i dati nei sotto-array temporanei
        for (int i = 0; i < n1; i++)L[i]=A[p+i];
        for (int j = 0; j < n2; j++)R[j]=A[q+1+j];
        int i=0,j=0;
        // Ciclo di fusione usando il for come richiesto
        for (int k = p; k <= r; k++) {
            if (i < n1 && (j >= n2 || L[i] <= R[j])) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
                // Se prendiamo da destra (R), l'elemento scavalca 
                // tutti quelli rimasti a sinistra (L)
            if (i < n1) inversioni += (n1 - i);
            
            }
        }
    return inversioni;
}

