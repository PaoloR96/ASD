#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
     //1.Definisco i casi di test
     printf("SAMPLE INPUT:");
     /* TEST 1: Caso Medio (Array disordinato)
     L'albero risultante sarà moderatamente bilanciato. 
     In questo scenario, la complessità temporale per la costruzione dell'albero si avvicina a O(n log n).*/
     int array1[] = {5, 3, 7, 2, 4, 8};
     int dim1 = sizeof(array1) / sizeof(array1[0]);
     printf("\n Caso di Test1:");
     StampaVettore(array1,dim1);
     /* TEST 2: Caso Peggiore 1 (Array già ordinato in modo crescente)
      Ogni nuovo nodo diventa il figlio destro del nodo precedente. 
      L'albero degenera in una lista concatenata verso destra.
      La complessità per l'inserimento sale a O(n^2).*/
     int array2[] = {1, 2, 3, 4, 5, 6, 7};
     int dim2 = sizeof(array2) / sizeof(array2[0]);
     printf("\n Caso di Test2:");
     StampaVettore(array2,dim2);
     /*TEST 3: Caso Peggiore 2 (Array ordinato in modo decrescente)
     Ogni nuovo nodo diventa il figlio sinistro del nodo precedente. 
     L'albero degenera in una lista concatenata verso sinistra.
     Anche qui, la complessità per l'inserimento sale a O(n^2).*/
     int array3[] = {9, 8, 7, 6, 5, 4, 3};
     int dim3 = sizeof(array3) / sizeof(array3[0]);
     printf("\n Caso di Test3:");
     StampaVettore(array3,dim3);
     //Stampa casi di test
     printf("SAMPLE OUTPUT:");
     printf("\n Output1:");
     CreazioneAlbero(array1, dim1);
     printf("\n Output2:");
     CreazioneAlbero(array2, dim2);
     printf("\n Output3:");
     CreazioneAlbero(array3, dim3);
    
     system("pause");
     return 0;
}

/*
Analisi Complessità:
La complessità complessiva dipende interamente dalla forma che assume l’albero durante la fase di costruzione, 
poiché i nodi vengono inseriti rispettando solo il vincolo di ricerca e non un criterio di bilanciamento.

Caso Migliore: O(n log n)
Condizione: L’albero generato è (quasi) perfettamente bilanciato.
Per quanto riguarda l’altezza si mantiene a log2(n). Inserire n nodi richiede un tempo di O(n log n) mentre 
 InordertreeWalk tocca ogni nodo una sola volta, costando O(n).
Totale: O(n log n) + O(n) = O(n log n)


Caso Peggiore: O(n^2)
Condizione: Il vettore di input è già ordinato (crescente o decrescente). L’albero degenera in una lista concatenata, perdendo del tutto il bilanciamento.
L’altezza diventa n. Il costo cumulato degli inserimenti diventa una serie aritmetica che asintoticamente costa O(n^2).
mentre InordertreeWalk rimane  Sempre O(n).
Totale: O(n^2) + O(n) = O(n^2)

*/