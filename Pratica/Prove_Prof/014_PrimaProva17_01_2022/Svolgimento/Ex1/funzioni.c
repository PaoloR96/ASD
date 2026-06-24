#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
void InserisciElementi(int A[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&A[i]);
}

long long DividiSequenza(int A[MAX],int p,int r){
    //1.Condizione di uscita:
    if(p>=r)return 0;
    //2.Creo la ricorsione andando a scomporre il problema
    int mid=p+(r-p)/2;
    long long OccSx=DividiSequenza(A,p,mid);
    long long OccDx=DividiSequenza(A,mid+1,r);
    long long Occ=CalcolaSwap(A,p,mid,r);
    return OccSx+Occ+OccDx;
    
}


long long CalcolaSwap(int A[MAX],int p,int q,int r){
    long long Occorrenze=0;
    //1.Definisco le dimensione dei due sotto-problemi
    int n1=q-p+1;//Dimensione del primo problema
    int n2=r-q;//Dimensione del secondo problema
    //2.Definisco i due sotto-vettori
    int L[n1+1],R[n2+1];
    //3.Copio il vettore A[r...p] in L[n1] ed R[n2]
    for (int i = 0; i < n1; i++)L[i]=A[p+i];
    for (int i = 0; i < n2; i++)R[i]=A[q+i+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    //4.Vado a contare il numero di swap
    int i=0,j=0;
    for (int k = p; k <= r; k++){
        //Nell’if confronto gli elementi e, se prendo quello di sinistra, aggiorno i senza generare nuove occorrenze.
        if (L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
            //Nell’else, invece, quando prendo un elemento da destra perché più piccolo di quello di sinistra, 
            //aggiorno le occorrenze contando tutte le coppie che si formano con gli elementi rimanenti in L, pari a (n1 - i)
            Occorrenze+=(n1-i);
        }
    }
    //5.Ritorna il numero di occorrenze
    return Occorrenze;
}
