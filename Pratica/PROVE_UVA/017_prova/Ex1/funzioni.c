#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void RiempiCasoTest(Test *T, int dim){
    T->numLibri = dim; //definisco la dim
    for (int i = 0; i < dim; i++)scanf("%d", &T->N[i]);//inserisco gli elementi
    scanf("%d", &T->M);//Definisco il target
}

int ComparaN(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;
   return x - y; //ordino in senso crescente
}


void CercaDifferenzaMin(int P[MAXl],int dim,int M){
    int diff=0, iBest=0,jBest=0;
    int min_d=INT_MAX;
    for (int i = 0; i < dim-1; i++){//per ogni elemento i
        //1.Calcolo il target iesimo
        int Target=M-P[i];
        //2.Trovo il mio target nell'intervallo (i+1,dim-1) in modo tale da evitare i duplicti
        int j=RicercaBinariaTarget(P,Target,i+1,dim-1);
        //3.Se ho un j! da -1 allota calcolo la differenza
        if(j!=-1){
            diff=P[j]-P[i]; //j>=i
            if(diff<min_d){
                min_d=diff; //aggiorno la differenza minina
                iBest=P[i];
                jBest=P[j]; 
            }
        }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", iBest, jBest);
}

int RicercaBinariaTarget(int P[MAXl],int Target,int low,int hight){
    while (low<=hight){
        //Calcolo il punto medio
        int mid=low+(hight-low)/2; // Evita overflow rispetto a (low+hight)/2
        //Abbiamo tre casi:
        //Caso 1: Elemento trovato, ritorna la posizione mid
        if(P[mid]==Target)return mid;
        // Caso 2: Se l'elemento nel mezzo è MINORE del target, cerca a DESTRA
        if (P[mid] < Target) low = mid + 1;
        // Caso 3: Se l'elemento nel mezzo è MAGGIORE del target, cerca a SINISTRA
        else hight = mid - 1;
        
    }
    return -1; //non abbiamo trovato niente
}