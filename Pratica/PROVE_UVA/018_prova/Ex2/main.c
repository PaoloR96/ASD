#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    char ListaParole[MAX][LEN]={0};
    int numTest=0;
    scanf("%d",&numTest);
    InserimentoDati(ListaParole,numTest);
    OrdinaParole(ListaParole, numTest);
    printf("SAMPLE OUTPUT:\n");
    ElaboraParole(ListaParole, numTest);
    system("pause");
    return 0;
}

/*
Complessità:O(N!)
*/