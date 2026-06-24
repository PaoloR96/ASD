#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int persone[4] = {1, 2, 5, 10};
    int n=4;
    //1.Odinamento
    qsort(persone,n,sizeof(int),ComparaValori);
    RisolviPercorso(persone,n);
   

    system("pause");
    return 0;
}