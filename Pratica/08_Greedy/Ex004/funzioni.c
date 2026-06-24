#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header
// Funzione per stampare un set di dati
void stampaSet(SetCentrifuga set) {
    printf("Camere: %d\n", set.camere);
    printf("Campioni: %d\n", set.campioni);
    printf("Masse: ");
    for(int i = 0; i < set.campioni; i++) {
        printf("%d ", set.masse[i]);
    }
    printf("\n");
}
//Metodo di compare per il qsort
int ComparaValori(const void *a,const void *b){
    int x= *(const int *)a;
    int y= *(const int *)b;
    return x - y; //ordinamento in senso crescente

    
}

int SommaCampioni(SetCentrifuga set){
    int sommaT=0;
    for (int i = 0; i < set.campioni; i++) sommaT+=set.masse[i];
    return sommaT;
}

SetCentrifuga RiempiSequenza( SetCentrifuga set_iniziale,int split){
    int Tmp[MAX_CAMPIONI];
    //in base allo split copio gli 0 nelle prime split locazioni
    for(int i=0;i<split;i++)Tmp[i]=0;
    for (int i = 0; i <set_iniziale.campioni; i++)Tmp[i+split]=set_iniziale.masse[i];
    //aggiorno la set_iniziale
    set_iniziale.campioni=set_iniziale.campioni+split;
    for (int i = 0; i <set_iniziale.campioni; i++)set_iniziale.masse[i]=Tmp[i];
    return set_iniziale;
}


void CalcolaSbilanciamento(SetCentrifuga s,double target){
        double SommaImbalance=0;
        for (int i = 0; i < s.camere; i++){
            //prendo la coppia di campioni(sx,dx) per ogni i
            int val1=s.masse[i];//prendo l'elemento di sinistra
            int val2=s.masse[s.campioni-i-1];//prendo l'elemento di sinistra
            //Calcoli
            double CM_i = (double)val1 + val2;          // Massa della camera i
            SommaImbalance += fabs(CM_i - target);      // Accumulo squilibrio
            printf(" %d:", i);
            if (val1 != 0) printf(" %d", val1);
            if (val2 != 0) printf(" %d", val2);
            printf("\n");
        }
        printf("IMBALANCE = %.5f\n\n", SommaImbalance);
}
