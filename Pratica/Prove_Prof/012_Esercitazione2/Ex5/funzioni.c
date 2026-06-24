#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void  RiempiElementi(int Vett[MAX],int dim){
    for (int i = 0; i < dim; i++){
        scanf("%d",&Vett[i]);
    }
}
int ComparaElementi(const void* a,const void * b){
    const int *b1=(const int*)a;
    const int *b2=(const int*)b;
    return (*b1 - *b2);
}
void TrovaElmento(int Biglie[MAX],int dimB,int Query[MAX],int dimQ){
    for (int i = 0; i < dimQ; i++){
        //Trovo l'elmento iesimo mediante ricercaBinaria
        int TrovaPosizione=RicercaBinaria(Biglie,dimB,Query[i]);
        if (TrovaPosizione!=-1){
            printf("%d found at %d\n",Query[i],TrovaPosizione+1);
        }else{
            printf("%d not found\n",Query[i]);
        }     
    }
}

int RicercaBinaria(int Biglie[MAX],int dimB,int target){
    //fase1:Inizializzo gli indici
    int low=0;
    int high=dimB-1;
    int asw=-1;
    //Fase2:Logica di ricerca
    while (low<=high){
        //2.A:Calcolo il punto medio
        int mid=low+(high-low)/2; //uso questo modo per evitare possibili overflow
        //Caso 1: Ho trovato l'elemento
        if (Biglie[mid]==target){
            asw=mid;
            high=mid-1;
         //Caso2:Nel caso in cui il confronto risuta > o <
        }else if (Biglie[mid]<target){
                low=mid+1;//mi sposto più a destra per trovare un soluzione migliore
        }else{
                high=mid-1;//mi sposto più a sinistra per trovare un soluzione migliore
        }
    }
    return asw;
}