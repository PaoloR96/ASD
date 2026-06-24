#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiVettore(int V[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&V[i]);
}

int ComparaElementi(const void *a,const void *b){
    int v1=*(const int *)a;
    int v2=*(const int *)b;
    return (v1-v2);//Ordino gli elementi del 
}

int TrovaDistanza(int V[MAX],int dim,int mediana){
    int distanzaTotale=0;
    for (int i = 0; i < dim; i++){
        distanzaTotale+=abs(V[i]-mediana);
    }
    return distanzaTotale;
}