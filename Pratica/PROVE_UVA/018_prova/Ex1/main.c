#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    Punto Coordinate[MAX];
    double Risultato[MAX];
    int N=0,index=0;
    while (index<MAX){
        scanf("%d",&N);
        if(N==0)break;
        //1.Riempio il caso di test
       RiempiCasoTest(&Coordinate[index], N);
        //1.a Ordino per X crescente, poi Y crescente
        qsort(Coordinate,N,sizeof(Punto),ComparaCoordinateXY);
        //2.Applico il dividi et impera
        Risultato[index]=CalcolaSequenza(Coordinate, N);
        //3.Passo al caso di test successivo
        index++;
    }
     printf("SAMPLE OUTPUT:\n");
     for (int i = 0; i < index; i++){
        if (Risultato[i] < LIMIT) {
            printf("%.4f\n", Risultato[i]); 
        } else {
            printf("INFINITY\n"); 
        }
     }
    system("pause");
    return 0;
}
/*Complessità: O(N*longN)*/