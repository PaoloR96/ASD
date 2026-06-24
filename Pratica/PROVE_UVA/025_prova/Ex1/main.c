#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int index=0;
    //Parametri matice
    int Matrice[N][M];
    int n=0,m=0;
    //Parametri query
    Query q[1000];
    int dim;
    //Salvo i risultati finali
    int Risultato[1000];
    printf("SAMPLE INPUT:\n");
    while (index <1000){
        //1.Inserimento dimensione e valori della matrice
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)break;
        RiempiMatrice(Matrice,n,m);
        //2.Inserimento Query
        scanf("%d",&dim);
        for (int i = 0; i < dim; i++)scanf("%d %d",&q[i].x,&q[i].y);
        //3.Calcolo area
        CalcolaCasoTestX(Matrice,m,n,q,dim,index);
        //4.Passo al caso di test successivo
        index++;
    }
    
    
   

    system("pause");
    return 0;
}

/*


Complessità: =(k*logM) con  k=numeroTest*dimQuery*N

*/