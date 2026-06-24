#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   
    int size=10,x=0;
    int A[size];
    /*Riempi Vettore A e B*/
    printf("Inserimento vettore A:");
    printf("\n");
    RiempiVettore(A,size);
    printf("definire x:");
    scanf("%d",&x);
    int pos= TrovaPosizioneX(A,0,size-1,0,x);
    if(pos!=0){
         printf("L'ultima pos in cui si trova %d e' %d",x,pos+1);
    }else{
        printf("L'elemento %d non e'presente, pertanto ha pos %d \n",x,pos);
    }
    system("pause");
    return 0;
}
/*Complessità O(logn)*/