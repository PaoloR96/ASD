#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void stampaTestCase(TestCase t) {
    printf("t (target) = %d\n", t.t);
    printf("n (numero elementi) = %d\n", t.n);

    printf("x (valori): ");
    for(int i = 0; i < t.n; i++) {
        printf("%d ", t.x[i]);
    }
    printf("\n");
}

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//{4, 6, {4, 3, 2, 2, 1, 1}},   // t=4, n=6, lista di 6 numeri
void trovaSomme(int A[], int n, int target, int index, int attuale[], int size, int sommaCorrente, int *trovato) {
      //Condizione di uscita: Se ho raggiunto il target stampo la sequenza
      if(sommaCorrente==target){
         StampaArray(attuale,size);
         *trovato = 1; // Segnaliamo che abbiamo trovato almeno una soluzione
         return;
      }
      //Condizione ricorsiva:provo ogni elemento di A in funzione di index
      for (int i = index; i < n; i++){
       // if (i > index && A[i] == A[i - 1]) continue;
         if(sommaCorrente+A[i]<=target){
            attuale[size]=A[i];
            //testo il prossimo valore della sequenza
            trovaSomme(A,n,target,i+1,attuale,size+1,sommaCorrente+A[i],trovato);


         }
      }
      
 
}
