#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header

void RiempiElementi(int Vett[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&Vett[i]);
}

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int TrovaPosizioneMax(int Vett[MAX],int dim){
    int Max=-1;
    int pos=0;
    for (int i = 0; i < dim; i++){
        if (Max<Vett[i]){
            Max=Vett[i];
            pos=i;
        }
    }
    return pos;
}

void flip(int Vett[MAX],int p){
    int i=0;
    int j=p;
    while (i<j){
        Swap(&Vett[i],&Vett[j]);
        i++;
        j--;
    }
}


void StampaElementi(int Vett[MAX],int dim){
     for (int i = 0; i < dim; i++)printf("%d ",Vett[i]);
     printf("\n");
}

void PancakeSorting(int Vett[MAX],int dim){
    //0.Stampo la sequenza che andrò ad analizzare
    StampaElementi(Vett,dim);
    for (int i = dim-1; i >= 0; i--){
        // 1. Trovo l'indice della posizione MAX fino a i (SOLO nella parte non ordinata) 
        int pos=TrovaPosizioneMax(Vett,i+1);
        //2.Valuto le possibili casistiche:
        // Caso A: Se pos == i, è già al suo posto in fondo, quindi lo saltiamo (nessun flip)
        if (pos!=i){
            // Caso B: Il massimo è nel mezzo. Eseguo il flip(pos) per portarlo in cima.
            if (pos !=0){
                flip(Vett,pos);
                // Stampa l'indice convertito: posizione "p" (n - indice)
                printf("%d ",dim-pos);
            }
            // Caso C: Il massimo è in cima, lo ribalto in fondo (i)
            flip(Vett,i);
            printf("%d ",dim-i);
        }
    }
    //3.La sequenza termina con uno 0
    printf("0\n");
}