#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int Insieme [MAX];
    int N=4,H=3;
    Risolvi(Insieme,N,H,0);
   

    system("pause");
    return 0;
}

/*Complessità:O(2^N)*/