#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header



void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++)scanf("%d",&A[i]);
}



void TrovaElemento(int A[][MAX], int Size[], int size){
    for (int i = 0; i < size; i++){
        int a1=A[i][0];// primo elemento
        int an=A[i][Size[i] - 1];// ultimo elemento
        int n=Size[i];//dimensione
        int d = (an - a1) / n;  // differenza comune (numero mancante considerato)
        int NumMancante=TrovaValoreMancante(A[i],0,n-1,a1,d);
        printf("%d\n",NumMancante);
    }
}

int TrovaValoreMancante(int A[],int start,int end,int a1,int d){
    /*quando l'intervallo si riduce a un solo indice*/
    if(start==end)
        return a1 + end * d;// Il valore mancante si trova qui
    /*ricorsione*/
    int mid=(start+end)/2;
    // Valore atteso nella progressione al centro
    int expected = a1 + mid * d;
    if(expected==A[mid])
        return TrovaValoreMancante(A,mid+1,end,a1,d); //trovo a dx
    else
        return TrovaValoreMancante(A,start,mid,a1,d); //trovo a sx

}
