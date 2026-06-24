#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Tartaruga T[MAX];
    int index=0;
    printf("SAMPLE INPUT:\n");
    while (index<MAX && scanf("%d %d",&T[index].Peso,&T[index].Forza)==2)index++;
    printf("SAMPLE OUTPUT:\n");
    //1.Ordino le tartarughe in base alla forza, in ordine crescente
    qsort(T, index, sizeof(Tartaruga), ComparaForza);
    //2.Definiamo la logica DP
    int DP[MAX];
    initDP(DP,index);
    //3.Calcola max altezza con DP
    int h=CalcolaDP(DP,T,index);
    printf("%d",h);
    

   

    system("pause");
    return 0;
}

/*
Compessitaà:O(N^2)

Ricorrenza:
*/