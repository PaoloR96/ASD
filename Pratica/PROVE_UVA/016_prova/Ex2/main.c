#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    CasoTest T[MAX];
    int index=0,numTest=0;
    scanf("%d",&numTest);
    printf("\n");
    while (index<numTest){
        scanf("%d",&T[index].dimensione);
        RiempiCasoTest(T[index].Matrice,T[index].dimensione);
        index++;
        printf("\n");
    }
    printf("SAMPLE OUTPUT:\n");
    index=0;
     while (index<numTest){
       
        ElaboraCasoTest(T[index].Matrice,T[index].dimensione);
        index++;
        printf("\n");
    }
    

    system("pause");
    return 0;
}

/*Complessità:O(T*(N^2*8^L)+(WlogW*L)) con :
                T casi di test
                L lunghezza max parola 
                8 direzioni(scelte) che posso considerare
                N*N numero di celle della tabella dove parte il backtrakking
                W*logW+L che corrisponde all'ordinamento delle W parole uniche trovate,dove ogni confronto dipende dalla lunghezza L della stringa           
                
*/