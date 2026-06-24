#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
//Stampo casi di test
void StampaCasiTest(int A[],int dim){
    for (int i = 0; i <dim; i++){
        printf("%d \n",A[i]);
    }
}
//Metodo per il qsort
int Compara(const void *a,const void *b){
        int x=*(const int *)a;
        int y=*(const int *)b;
        if(x>y)return 1;//ordino in senso crescente
        if(x<y)return -1;
        return 0;
}
//Logica Greedy
void CalcolaSequenza(CasoTest C){
    //definisco le variabili
    int TesteTagliate=0;
    int BestCosto=0;
    int i=0; //indice per la testa
    int j=0; //indice per i cavalieri
    //poichè sono ordinati li scorriamo insieme
    while (i<C.n && j<C.m){
            if(C.N[i]<=C.M[j]){
                TesteTagliate++;
                BestCosto+=C.M[j];// Paga l'altezza del cavaliere
                i++;//passo alla prossima testa
            }
            j++;// In ogni caso, il cavaliere attuale è stato usato o scartato
    }
    // Verifica se tutte le teste sono state tagliate
    if (TesteTagliate == C.n) {
            printf("%d\n", BestCosto);
    } else {
        printf("Loowater is doomed!\n");
    }
    
}

