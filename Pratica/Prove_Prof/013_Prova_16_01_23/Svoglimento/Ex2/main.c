#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c


int main() {
    printf("SAMPLE INPUT:\n");
    int V[MAX];
    bool Ris[MAX];   
    bool trovato[MAX]; 
    int index=0,test=0,dim=0;
    scanf("%d",&test);
    for (int i = 0; i < test; i++){
        //Fase1:Inserimento valori
        scanf("%d",&dim);
        RiempiVettore(V,dim);
        for (int i = 0; i < dim; i++)trovato[i] = false;
        //Fase2:Verifico la sequenza
        Ris[i]=IsJolly(V,trovato,dim);
    }

   printf("SAMPLE OUTPUT:\n");
   for (int i = 0; i < test; i++){
        if (Ris[i]==true){
            printf("It's Jolly!\n");
        }else{
            printf("No Jolly!\n");
        }
    }

    system("pause");
    return 0;
}

/*Complessità:O(Test*N)*/