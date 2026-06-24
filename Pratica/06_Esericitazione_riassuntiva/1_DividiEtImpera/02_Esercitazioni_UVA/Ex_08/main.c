#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    long long A[SIZE]; 
    long long dim[SIZE];       
    long long T=0,index = 0;

    printf("SAMPLE INPUT:\n");
    scanf("%lld",&T);
    while (T!=0) {
        scanf("%lld",&A[index]);
        index++;
        T--;    
    }

    printf("SAMPLE OUTPUT:\n");
    TrovaK(A, index);
    

    system("pause"); 
    return 0;
}

/*Complessità O(logn)*/