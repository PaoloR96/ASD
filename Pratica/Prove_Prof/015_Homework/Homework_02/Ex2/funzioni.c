#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiVettore(int A[MAX],int dim){
    for (int i = 0; i < dim; i++)scanf("%d",&A[i]);
}

int ComparaElementi(const void*a,const void*b){
    int x1=*(const int*)a;
    int x2=*(const int*)b;
    return(x1 -x2);//ordino in modo crescente gli elementi
}
void StampaRisultati(int Risultato[MAX],int dim){
    for (int i = 0; i < dim; i++)printf("%d ",Risultato[i]);
    printf("\n");
}

void TrovaElementiMinori(int A[MAX],int dim){
    int Risultato[MAX];
    int A_ordinato[MAX];
    
    //1. Creo una copia per NON modificare l'ordine originale di A
    for(int i = 0; i < dim; i++)A_ordinato[i] = A[i];
    //2.Ordino gli elementi tramite il metodo qsort
    qsort(A_ordinato, dim, sizeof(int), ComparaElementi);
    //2.Inizio con la ricerca per creare il vettore finale richiesto dal problema
    for (int i = 0; i < dim; i++)Risultato[i]=RicercaElementi(A_ordinato,dim,A[i]);
    StampaRisultati(Risultato,dim);    
}

int RicercaElementi(int A[MAX],int dim,int target){
    int low=0;
    int high=dim-1;
    int contatore=0;
    while (low<=high){
            //1.Calcolo il punto medio
            int mid=low+(high-low)/2;
            //2.Gestisco le varie casistiche:
            //a)L'Elemento è <=del target
            if (A[mid]<=target){
                contatore=mid+1;//gli elementi <= sono esattamente mid + 1
                low=mid+1;//mi sposto più a dx
            }else if (A[mid]>target){
                high=mid-1;//mi sposto più a sx
            }
    }
    //3.Ritornano il numero di elementi <= del target
    return contatore; 
}

