#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   

    int T=0,A[MAX][MAX],Size[MAX],index=0;
    printf("Sample Input:\n");
    printf("Definsci i casi di Test:");
    scanf("%d",&T);
    while (T!=0){
        scanf("%d",&Size[index]);
        RiempiVettore(A[index],Size[index]);
        index++;
        T--;
    }
    printf("Sample Output:\n");
    TrovaElemento(A,Size,index);
    
    system("pause");
    return 0;
}
/* 
 * Complessità: O(log n)
 * 
 * La funzione effettua una ricerca binaria sull'array:
 * - Se il valore atteso nella progressione coincide con A[mid], 
 *   significa che tutti gli elementi fino a mid sono corretti, quindi la ricerca continua a destra.
 * - Se invece il valore atteso non coincide con A[mid], 
 *   significa che l'elemento mancante si trova a sinistra, quindi la ricerca continua a sinistra.
 * 
 * La ricorsione dimezza l'intervallo a ogni passo, garantendo O(log n).
 */
