#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int test=0,dim=0;
    int Vett[MAX],Ris[MAX];
    printf("SAMPLE INPUT:\n");
    scanf("%d",&test);
    for (int i = 0; i < test; i++){
        //Definisco la dimensione e gli elementi
        scanf("%d",&dim);
        for (int j = 0; j < dim; j++)scanf("%d",&Vett[j]);
        int offset=(Vett[dim-1]-Vett[0])/dim;
        Ris[i]=TrovaElementoX(Vett,dim,offset);
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < test; i++){
        printf("%d \n",Ris[i]);
    }

    system("pause");
    return 0;
}
/*
Complessità: O(logN)

Come suggerisce il problema,potrei avere una complessità lineare sfruttando il meccanismo
dei puntatori.Dopo aver calcolato l'offset,avrò:

int TrovaElementoX(int *Vettore, int offset){
    for(int i=0;i<dim-1;i++){
        if(*(Vettore+i+1)-*(Vettore+i)!=offset){
            int elementoX=*(Vettore+i)+offset;
            return elementoX;
        }
    }
    return-1; //non ho trovato l'elemento
}

*/