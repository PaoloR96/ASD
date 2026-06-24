#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    char Risultato[100][100];
    char StringaX[100];
    const char *words[] = {"apple", "ape", "april", "applied"};
    int size = sizeof(words) / sizeof(words[0]);
    printf("SAMPLE INPUT:\n");
    for (int i = 0; i < size; i++)printf("%s\n", words[i]);
    printf("SAMPLE OUTPUT:\n");
    printf("Output: %s\n", TrovaPrefissoComune(words, size));
    

    system("pause");
    return 0;
}
/*
Complessità:O(N*M) dove n=size (numero stringhe) , m=lunghezza del prefisso comune
*/