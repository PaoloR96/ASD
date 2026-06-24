#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void stampa(int A[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int Compara(const void * a,const void *b){
    int x=*(const int *)a;
    int y=*(const int *)b;
    if(x>y)return 1;
    if(x<y)return -1;
    return 0;

}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int DefinisciOccorrenze(int A[], int p, int r) {
    //condizone di uscita
    if (p == r) return 1;
    //calcolo il punto medio
    int q = (p + r) / 2;
    //riciorsione
    int occSx = DefinisciOccorrenze(A, p, q);
    int occDx = DefinisciOccorrenze(A, q + 1, r);
    int occ = CalcolaOccorrenza(A, p, q, r);
    //ritorna l'occorrenza massima
    return max(max(occSx, occDx), occ);
}


int CalcolaOccorrenza(int A[], int p,int q,int r){
        int cont=0;
        int valX=A[q];
        for (int i = p; i <= r; i++){
                if(valX==A[i])cont++;
        }
        return cont;
}

void IncastraPila(int V[],int dim,int k){
        // 1. Stampa il numero minimo di pezzi k
        printf("%d\n", k);
        for (int i = 0; i < k; i++) { // Per ogni riga
            int primo = 1;
            for (int j = i; j < dim; j=j+k){//salto di k in k, in modo tale da comporre la iesima pila
                if (!primo) printf(" ");
                printf("%d", V[j]);
                primo = 0;
            }
            printf("\n");
        }
}