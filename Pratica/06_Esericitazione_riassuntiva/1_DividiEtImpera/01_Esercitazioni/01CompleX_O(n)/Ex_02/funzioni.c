#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void GeneraNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 15;
    }
}

int CalcolaOcc(int A[],int L,int R,int start,int end){
        /*caso base:ho un solo elemento*/
        if(start==end){
            if(A[start]>=L && A[start]<=R)return 1;
            else return 0;
        }
        /*caso ricorsivo: vado a suddividere il vettore*/
        int mid=(start+end)/2;
        int left=CalcolaOcc(A,L,R,start,mid);
        int right=CalcolaOcc(A,L,R,mid+1,end);
        return left+right;
}

void TrovaNumeri(int A[], int size){
    int L=0,R=0;
    printf("Definire gli estremi con L<R:");
    scanf("%d %d",&L,&R);
    printf("\n");
    int occ=CalcolaOcc(A,L,R,0,size-1);
    printf("Gli elementi compresi tra L=%d e R=%d,sono: %d",L,R,occ);
    
}


/*
La complessità dell’algoritmo è:T(n)=O(n)

perché, anche se viene usata la tecnica Divide et Impera, ogni elemento dell’array viene comunque visitato esattamente una volta.

Infatti, la ricorrenza è:T(n)=2T(n/2)+O(1)

dove:
*2T(n/2) deriva dal fatto che dividiamo l’array in due parti e le analizziamo entrambe

*O(1) è il costo per combinare i risultati (somma dei conteggi)


*/