#include <stdio.h>
#include "funzioni.h"

/*
D:profondità
I:iesima palla
*/
int TrovaPosizione(int D, int I) {
    int P = 1;//posizione di partenza
    for (int depth = 1; depth < D; depth++) {
        //valuto I
        if (I % 2 == 1) {  
            //Se I dispari → sinistra
            P = P * 2;//calcolo la nuova posizione
            I = (I + 1) / 2; //aggiorno I
        } else {
            //Se I pari → destra
            P = P * 2 + 1;//calcolo la nuova posizione
            I = I / 2;//aggiorno I
        }
    }
    return P;
}


void InserisciElementi(int A[][2], int size){
    for (int  i = 0; i < size; i++){
        scanf("%d %d",&A[i][0],&A[i][1]);
    }
}


void CalcolaPosizione(int A[][2],int dim[20],int start,int end){         
            if (start==end)return;
            for (int i = 0; i < dim[start]; i++){              
                int P = TrovaPosizione(A[i][0],A[i][1]);             
                printf("Posizione finale per D=%d, I=%d: %d\n", A[i][0], A[i][1], P);   
            }     
            CalcolaPosizione(A,dim,start+1,end);       
}