#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
int main() {
    int A[20][2];
    int dim[20];
    int index = 0;
    int temp;
    printf("Sample Input:\n");
    while (index < 20) {
        scanf("%d", &temp);
        if (temp == -1)break;
        dim[index] = temp;
        InserisciElementi(A, temp);
        index++;
    }
    printf("Sample Output:\n");
    CalcolaPosizione(A,dim,0,index);
    printf("\n");
    system("pause");
    return 0;
}

/*
La complessità del programma è O(N) perché ogni coppia (D, I) viene letta e processata una sola volta.
 La ricorsione in CalcolaPosizione scorre semplicemente i blocchi senza ripetere operazioni sulle coppie già elaborate, 
 e la funzione TrovaPosizione ha tempo costante (profondità massima limitata), 
 quindi il numero totale di operazioni cresce linearmente con il numero totale di coppie.

*/
