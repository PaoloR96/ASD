#include <stdio.h>
#include "funzioni.h"


// Funzione per trovare il gruppo k usando ricorsione sicura
long long modular_exponentiation(long long B, long long P, long long M){
    if(P==0)return 1;// B^0 = 1
    /*RICORSIONE:*/
    long long half = modular_exponentiation(B, P / 2, M);
    long long result = (half * half) % M;
    if (P % 2 == 1) // Se P è dispari, moltiplica ancora per B
        result = (result * B) % M;
     return result;
}

// Funzione per calcolare la posizione relativa all’interno del gruppo
void CalcolaK(long long B[],long long P[],long long M[],long long size) {
    for (long long j = 0; j < size; j++) {
        long long K= modular_exponentiation(B[j],P[j],M[j]);
        printf("%lld\n",K);
        
    }
}
