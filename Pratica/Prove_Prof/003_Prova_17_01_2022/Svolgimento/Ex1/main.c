#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Test=0;
    int ris[100];
    int dim=0;
    int A[100];
    for (int i = 0; i<100; i++){
        scanf("%d",&dim);
        if(dim==0)break;
        //Riempio i vettore
        for(int i=0;i<dim;i++)scanf("%d",& A[i]);
        //Calcolo il numero di spostamenti
        ris[i]=CalcolaSpostamenti(A,0,dim-1); 
        Test++;
    }
    
    printf("SAMPLE OUTPUT: \n");
      for (int i = 0; i < Test; i++)printf("%d \n",ris[i]);
   

    system("pause");
    return 0;
}

/*Complessità: O(n*logn)*/