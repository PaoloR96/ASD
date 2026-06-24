#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int test=0,index=0;
    int dim=0;
    int X[MAX],Y[MAX][MAX];
    scanf("%d",&test);
    while (index<test){
        scanf("%d",&dim);
        //1.Inserisco la sSequenza1
        for (int i = 0; i < dim; i++)scanf("%d",&X[i]);
        //2.Inserisco la il gruppo di sequenze che saranno cofrontate con la Seqeunza1
        for (int i = 0; i < dim-1; i++){
                for (int j = 0; j < dim; j++){
                    scanf("%d",&Y[i][j]);
                }
        }
        printf("0\n");
        //3.Elaboro il caso di test appena inserito
        printf("TEST OUTPUT:\n");
        CalcolaIesimoCasoTest(X,Y,dim);
        //4.Passo al prossimo caso di test
        index++;
        printf("\n");
    }
    system("pause");
    return 0;
}

/*
Complessità:O(dim*dim)
Ricorrenza:     Se i caratteri sono uguali allora   DP[i][j]=DP[i-1][j-1]+1 
                Se i caratteri sono diversi allora  DP[i][j]=max(DP[i-1][j],DP[i][j-1]) 

*/