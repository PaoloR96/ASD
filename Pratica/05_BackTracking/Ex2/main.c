#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {

    int S[]={1,2,3,4};
    int n=4;
    int k=2;
    GeneraCombinazioni(S,k,n);

    system("pause");
    return 0;
}
