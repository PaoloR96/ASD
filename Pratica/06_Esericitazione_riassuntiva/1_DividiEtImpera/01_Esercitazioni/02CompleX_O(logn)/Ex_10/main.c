#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int size=10,k=0;
    int A[size];
    printf("Sample Input:\n");
    printf("Riempi Vettore:");
    RiempiVettore(A, size);
    printf("Definisci k:");
    scanf("%d",&k);
    printf("Sample Output:\n");
    int scelta= TrovaValore(A,0,size-1,k);
    if(scelta==1){
        printf("Vero");
    }else{
        printf("Falso");
    }

    system("pause");
    return 0;
}
/*Complessità T(n)=O(logn)*/