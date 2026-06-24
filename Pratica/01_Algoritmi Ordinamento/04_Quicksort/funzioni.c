#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void GeneraNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101;
    }
}
void Swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
/*Metodi QuickSort*/
void Quicksort(int A[],int p,int r){
    if(p<r){
        int q=Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}
int Partition(int A[],int p, int r){
    int pivot=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j]<=pivot){
            i++;
            Swap(&A[i],&A[j]);  
        }
    }
    Swap(&A[i+1],&A[r]);
    return i+1;
}

/*
Array Iniziale: A = [30, 64, 59, 41, 24, 53, 50, 5, 65, 90]

1) Chiamata iniziale → Pivot = A[9] = 90; i = -1
   Tutti gli elementi ≤ 90 → nessuno scambio effettivo.
   Swap finale: A[9] <-> A[9]
   Array: [30, 64, 59, 41, 24, 53, 50, 5, 65, 90]; q = 9
   Ricorsione:
      Sinistra → Quicksort(A, 0, 8)
      Destra → (vuota)

2) PARTITION 2 → (p = 0, r = 8) Pivot = A[8] = 65; i = -1
   Nessuno scambio necessario.
   Array: [30, 64, 59, 41, 24, 53, 50, 5, 65, 90]; q = 8
   Ricorsione:
      Sinistra → Quicksort(A, 0, 7)
      Destra → (vuota)

3) PARTITION 3 → (p = 0, r = 7) Pivot = A[7] = 5; i = -1
   Nessun elemento ≤ 5
   Swap finale: A[0] <-> A[7] → (30 ↔ 5)
   Array: [5, 64, 59, 41, 24, 53, 50, 30, 65, 90]; q = 0
   Ricorsione:
      Sinistra → (vuota)
      Destra → Quicksort(A, 1, 7)

4) PARTITION 4 → (p = 1, r = 7) Pivot = A[7] = 30; i = 0
   Swap: A[1] <-> A[4] (64 ↔ 24)
   Swap finale: A[2] <-> A[7] (59 ↔ 30)
   Array: [5, 24, 30, 41, 64, 53, 50, 59, 65, 90]; q = 2
   Ricorsione:
      Sinistra → Quicksort(A, 1, 1)
      Destra → Quicksort(A, 3, 7)

5) PARTITION 5 → (p = 3, r = 7) Pivot = A[7] = 59; i = 2
   Swap: A[4] <-> A[5] (64 ↔ 53)
   Swap: A[5] <-> A[6] (64 ↔ 50)
   Swap finale: A[6] <-> A[7] (64 ↔ 59)
   Array: [5, 24, 30, 41, 53, 50, 59, 64, 65, 90]; q = 6
   Ricorsione:
      Sinistra → Quicksort(A, 3, 5)
      Destra → Quicksort(A, 7, 7)

6) PARTITION 6 → (p = 3, r = 5) Pivot = A[5] = 50; i = 2
   Swap finale: A[4] <-> A[5] (53 ↔ 50)
   Array: [5, 24, 30, 41, 50, 53, 59, 64, 65, 90]; q = 4
   Ricorsione:
      Sinistra → Quicksort(A, 3, 3)
      Destra → Quicksort(A, 5, 5)

Array finale ordinato:
[5, 24, 30, 41, 50, 53, 59, 64, 65, 90]


*/

/*
Analisi della Complessità di Quicksort

1. Complessità del Partizionamento
----------------------------------
La complessità di Quicksort dipende principalmente da quella di PARTITION.

- Caso peggiore (Worst Case, WC):
  Quando, ad ogni chiamata, PARTITION genera un sottoproblema con n-1 elementi e uno con 0 elementi.
  Ricorrenza: T(n) = T(n-1) + T(0) + O(n) = T(n-1) + O(n)
  Sostituendo iterativamente si ottiene la somma dei primi n numeri naturali: O(n^2)
  => WC = O(n^2)

- Caso migliore (Best Case, BC):
  Quando PARTITION produce due sottoproblemi bilanciati di dimensione circa n/2.
  Ricorrenza: T(n) = 2T(n/2) + O(n)
  Risolvendo: T(n) = O(n log n)

2. Caso Medio (Average Case, AC)
--------------------------------
- Nella pratica, Quicksort si comporta spesso vicino al BC.
- Esempio di partizioni sbilanciate 9:1:
  Sottoproblemi: 9/10 * n e 1/10 * n
  Ricorrenza: T(n) = T(9/10 * n) + T(1/10 * n) + cn (c = costante del partizionamento)

- Analizzando l’albero delle chiamate:
  - Ramo corto termina presto (profondità log base 10 di n)
  - Ramo lungo termina all’estrema destra
  - Ogni livello ha costo massimo cn
  - Profondità complessiva O(log n) → Costo totale O(n log n)

- Questo vale per qualsiasi rapporto costante (es. 99:1)

3. Intuizione sul Caso Medio Reale
----------------------------------
- Rapporto tra sottoproblemi non fisso
- Mix di partizioni buone e cattive:
  - Prima WC (0 e n-1), poi BC (n-1 diviso a metà)
  - Costo totale = O(n) + O(n) = O(n) a livello locale
  - Due partizioni successive WC e BC pesano come una BC: O(n log n)

4. Analisi del Worst Case di Quicksort
--------------------------------------
- Ricorrenza generale WC:
  T(n) = max_{0 <= q <= n-1} (T(q) + T(n-1-q)) + O(n)
  q = dimensione del sottoproblema più grande

- Massimizzando il tempo:
  - Funzione concava verso l’alto → massimo agli estremi (q=0 o q=n-1)
  - Ricorrenza: T(n) <= c(n-1)^2 + O(n) = O(n^2)

Conclusione:
-------------
- WC: O(n^2)
- BC: O(n log n)
- AC: O(n log n)



*/