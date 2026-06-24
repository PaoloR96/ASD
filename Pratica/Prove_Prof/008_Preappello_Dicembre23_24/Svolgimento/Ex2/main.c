#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    char ListaParole[MAX][MAX];
    int Test=0;
    int index=0;
    scanf("%d",&Test);
    while (getchar() != '\n');
    //1.Riempio i casi di test
    while (index<Test){
        if(fgets(ListaParole[index],MAX,stdin)!=NULL){
            //Rimuovo lo spazio
            ListaParole[index][strcspn(ListaParole[index], "\n\r")] = '\0';
        }
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    char Insieme[MAX];
    for(int i = 0; i < Test; i++) {
        GeneraCombinazione(ListaParole[i],0,Insieme,0);
        printf("*END*\n");
    }
   
    system("pause");
    return 0;
}
/*Complessità:O(2^N)*/