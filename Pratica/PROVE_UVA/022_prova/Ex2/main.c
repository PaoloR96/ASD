#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int Val[MAX],Catena[MAX],index=0;
    int valTmp=0;
    printf("SAMPLE INPUT: \n");
    while (index<MAX){
        scanf("%d",&valTmp);
        if(valTmp==0)break;
         Val[index]=valTmp;
         index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++) {
            int target = Val[i];
            if (target == 1) {
                printf("1\n");
                continue;
            }

            trovato = false;
            Catena[0] = 1; // La catena parte sempre da 1

        // Partiamo dalla profondità minima teorica log2(n)
        int min_m = (int)ceil(log2(target)) + 1;

        // Iterative Deepening: aumenta m finché non trovi la catena minima
        for (int m = min_m; ; m++) {
            TrovaSequenza(m,target, Catena,1);
            if (trovato) break;
        }
    }
    
    
   

    system("pause");
    return 0;
}

/*
Complessità: O(b^m) con b numero di possibili somme ai+aj ed m=lunghezza minima della catena

*/