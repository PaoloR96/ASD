#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   

    int x[N]={1, 3, 3, 5, 8, 10, 11, 11, 15, 16, 18, 19, 20, 25};
    int y=4;
    StampaArray(x, 14);
    printf("\n");
    CalcolaRicorsivo(x,y);


    system("pause");
    return 0;
}
