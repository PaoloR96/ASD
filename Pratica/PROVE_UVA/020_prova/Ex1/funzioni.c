#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

// Funzione di comparazione per qsort
int Compara(const void *a, const void *b) {
    long long arg1 = *(const int*)a;
    long long arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}