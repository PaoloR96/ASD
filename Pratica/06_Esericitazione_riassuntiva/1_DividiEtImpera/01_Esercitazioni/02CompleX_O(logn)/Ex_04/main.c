#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int A=5,n=11;
    int prodotto=TrovaSommeParziali(A,n);
    printf("\n");
    printf("il prodotto %d*%d=%d",A,n,prodotto);
    system("pause");
    return 0;
}

/*Complessità O(logn)*/


/*
Se A=5,n=11; ===>A*n=55

Sequenza di calcoli:

5*5 = 25 → corrisponde a n_left = 5
6*5 = 30 → corrisponde a n_right = 6

Poi i sottoproblemi di 5:

2*5 = 10
3*5 = 15

Sottoproblemi di 2:

1*5 = 5
1*5 = 5

Sottoproblemi di 3:

1*5 = 5
2*5 = 10

Sottoproblemi di 2:

1*5 = 5
1*5 = 5

Sottoproblemi di 6:

3*5 = 15
3*5 = 15

Sottoproblemi di 3:

1*5 = 5
2*5 = 10

Sottoproblemi di 2:

1*5 = 5
1*5 = 5

*/
