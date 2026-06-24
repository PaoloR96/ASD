#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void GeneraNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101;
    }
}
/*Metodi MergeSort*/
void Merge(int A[],int p,int q,int r){
    //definisco la dimensione dei due sotto-vettori
     int n1=q-p+1;
     int n2=r-q;
    //istanzio i due vettori L,R
    int L[n1+1],R[n2+1];
    //Diramo A[r] in L[n1]ed R[n2]
    for(int i=0;i<n1;i++)L[i]=A[p+i];
    for(int j=0;j<n2;j++)R[j]=A[q+1+j];
    //aggiungo le due sentinelle
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    int i=0,j=0;
    //unisco in due vettori L,R con A
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }      
        
}
void MergeSort(int A[],int p,int r){
    if(p<r){
        //calcolo il punto medio
        int q=(p+r)/2;
        //ordino la parte A[p....q]
        MergeSort(A,p,q);
        //ordino la parte A[p+1....r]
        MergeSort(A,q+1,r);
        //merge completo
        Merge(A,p,q,r);
    }
}
 /*
Array iniziale: [47, 78, 88, 20, 74, 50, 71, 71, 27, 77]

Step 1: Divisione ricorsiva (albero):

[47,78,88,20,74,50,71,71,27,77]
├── [47,78,88,20,74]
│   ├── [47,78,88]
│   │   ├── [47,78]
│   │   │   ├── [47]
│   │   │   └── [78]
│   │   └── [88]
│   └── [20,74]
│       ├── [20]
│       └── [74]
|
|
└── [50,71,71,27,77]
    ├── [50,71,71]
    │   ├── [50,71]
    │   │   ├── [50]
    │   │   └── [71]
    │   └── [71]
    └── [27,77]
        ├── [27]
        └── [77]

Step 2: Merge dei vari sotto-array base 
Step 3: Merge finale
 */       

/*
Complessità:
Consideriamo T(n) il tempo di esecuzione di un problema di dimensione n; 

1)Caso base:se la dimensione è abbastanza piccola (n<c) la soluzione impiegherà un tempo costante che de niamo come O-(1).

2)Caso generale:Supponiamo di suddividere il problema originale in a sottoproblemi, ciascuno di dimensione n/b, 
cioè una frazione 1/b della dimensione del problema iniziale.La risoluzione di ciascun sottoproblema richiede un tempo T(n/b).
Per risolvere tutti i a sottoproblemi avremo quindi un tempo complessivo pari a a·T(n/b).Se indichiamo con:
    D(n) il tempo necessario per dividere il problema nei sottoproblemi,

    C(n) il tempo necessario per combinare le soluzioni dei sottoproblemi e ottenere la soluzione del problema originale,

allora la ricorrenza per il tempo totale T(n) può essere espressa come:

     { O-(1)    if n<c
T(n)={
     {
     {T(n)=a⋅T(n/b)+D(n)+C(n)    altrimenti

*/