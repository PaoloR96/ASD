#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header



void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++)scanf("%d",&A[i]);
}

int SommaParziale(int A[], int start,int end){
    /*0.condizione di uscita*/
    if(start>end)return 0;
    /*1.condizione: elemento base*/
    if(start==end)return A[start];
    /*2.condizione: N elementi*/
    int mid=(start+end)/2;
    return  SommaParziale(A,start,mid)+ SommaParziale(A,mid+1,end);

}

void TrovaElemento(int A[][MAX], int Size[], int size){
    for (int i = 0; i < size; i++){
        int end = Size[i];
        int sommaParz = SommaParziale(A[i], 0, end);
        int SommaTot=((Size[i]+1) * (A[i][0] + A[i][Size[i] - 1])) / 2;
        int NumMancante = SommaTot - sommaParz;
        printf("%d\n",NumMancante);
    }
}
/*Questa soluzione è di tipo O(N) e non logaritimica, in quanto ogni elemento del vettore viene sommato una volta
T(n)=2T(n/2)+O(1)⟹T(n)=O(n)

Ps:soluzione semplice O(n)

*/