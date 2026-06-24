#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/* Puntatore STATICO */
static CasoTest *ct_ref;
/* Comparatore per qsort */
int ComparaElementi(const void *a, const void *b) {
    int i = *(const int *)a;
    int j = *(const int *)b;
    return ct_ref->posizione[i] - ct_ref->posizione[j];
}
/* Ordinamento */
void OrdinaCaso(CasoTest *ct, int n) {
    int indici[MAX];
    int seq_tmp[MAX];
    int pos_tmp[MAX];

    /* inizializza indici */
    for (int i = 0; i < n; i++) {
        indici[i] = i;
    }

    /* assegna riferimento */
    ct_ref = ct;

    /* ordina indici */
    qsort(indici, n, sizeof(int), ComparaElementi);

    /* riordina array */
    for (int i = 0; i < n; i++) {
        seq_tmp[i] = ct->Sequenza[indici[i]];
        pos_tmp[i] = ct->posizione[indici[i]];
    }

    for (int i = 0; i < n; i++) {
        ct->Sequenza[i] = seq_tmp[i];
        ct->posizione[i] = pos_tmp[i];
    }
}


void InizializzaDP(int DP[MAX+1][MAX+1],int dim){
    for (int i = 0; i < dim+1; i++){
        for (int j = 0; j < dim+1; j++)DP[i][j]=0;
    }
}

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int CalcolaSequenzaDP(int DP[MAX+1][MAX+1],int sequenzaCorretta[MAX],int SequenzaStudente[MAX] ,int dim){
        for (int i = 1; i <= dim; i++){ //per ogni sequenza corretta i
            for (int j = 1; j <= dim; j++){ //per ogni sequenza di uno studente j
                if(sequenzaCorretta[i-1]==SequenzaStudente[j-1]){
                    DP[i][j]=DP[i-1][j-1]+1;
                }else{
                    DP[i][j]=max2(DP[i-1][j],DP[i][j-1]);
                }
            }
        }
        return DP[dim][dim];//risultato finale della LCS
}