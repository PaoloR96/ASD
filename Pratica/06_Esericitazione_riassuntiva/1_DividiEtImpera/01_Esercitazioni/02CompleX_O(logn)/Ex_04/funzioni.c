#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaParziale(int A,int n){
    int prod=n*A;
    printf("%d*%d=%d \n",n,A,prod);
}

int TrovaSommeParziali(int A,int n){
    /* caso base */
    if(n == 0) return 0;
    if(n == 1) return A;
    /*caso ricosivo:*/
    //definisco gli n/k parziali di N
    int n_left=(n)/2;
    int n_right=n-n_left;
    //stampo i prodotti parziali
    StampaParziale(A,n_left);
    StampaParziale(A,n_right);
    //passo alla somma parziale successiva
    int SommaParzLeft=TrovaSommeParziali(A,n_left);
    int SommaParzRight=TrovaSommeParziali(A,n_right);
    
    return SommaParzLeft+SommaParzRight;

}