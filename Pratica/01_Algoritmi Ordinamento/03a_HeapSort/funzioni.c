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
/*Metodi HeapSort*/
int left(int i){ return 2*i+1;}
int right(int i){ return 2*i+2;}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*MaxHeapify è la procedura fondamentale che mantiene la proprietà del Max-Heap.
Dato un nodo i, supponendo che i suoi due sottoalberi siano già heap validi, 
la funzione verifica se il padre A[i] viola la proprietà dell’heap*/

void MaxHeapify(int A[], int i, int size){
    int massimo = i;
    int l = left(i);
    int r = right(i);

    if(l < size && A[l] > A[massimo]) massimo = l;
    if(r < size && A[r] > A[massimo]) massimo = r;
    //Se il massimo non è il padre, scambia i valori e richiama ricorsivamente MaxHeapify sul figlio più grande.
    if(massimo != i){
        swap(&A[i], &A[massimo]);
        MaxHeapify(A, massimo, size);
    }
}

/*
BuildMaxHeap ha il compito di trasformare un array qualsiasi in un max-heap, 
cioè in una struttura logica ad albero binario che rispetta una proprietà fondamentale:
Ogni nodo dell’albero è maggiore o uguale ai suoi figli.

Perché parte da i = size/2 - 1?
Gli indici da size/2 in poi rappresentano le foglie: non hanno figli, quindi non serve sistemarle.
size/2 - 1 è l’ultimo nodo che ha almeno un figlio
*/

void BuildMaxHeap(int A[], int size){
    for(int i = size/2 - 1; i >= 0; i--)
        MaxHeapify(A, i, size);
}
/*HeapSort utilizza il Max-Heap costruito in precedenza per ordinare l’array in modo crescente*/
void HeapSort(int A[], int size){
    BuildMaxHeap(A, size);
    for(int i = size - 1; i > 0; i--){
        swap(&A[0], &A[i]);
        MaxHeapify(A, 0, i);
    }
}
/*
Array iniziale:
Indice: 0  1  2  3  4  5  6  7  8  9
Valore: 31 76 85 25 54 54 23 40 63 41

FASE 1: Costruzione del Max-Heap

HeapSort trasforma l’array in un Max-Heap, un albero binario completo in cui ogni nodo è maggiore o uguale ai suoi figli.
          31
       /      \
     76        85
   /   \     /   \
 25    54   54   23
 / \  
40  63
 \
 41
Primo scambio: nodo 25 con figlio massimo 63
          31
       /      \
     76        85
   /   \     /   \
 63    54   54   23
 / \  
40  25
 \
 41

Array aggiornato: 31, 76, 85, 63, 54, 54, 23, 40, 25, 41

Scambio della radice con massimo figlio: 31 ↔ 85
          85
       /      \
     76        31
   /   \     /   \
 63    54   54   23
 / \  
40  25
 \
 41
Array aggiornato: 85, 76, 31, 63, 54, 54, 23, 40, 25, 41

Prossimo scambio: nodo 31 con figlio massimo 54
          85
       /      \
     76        54
   /   \     /   \
 63    54   31   23
 / \  
40  25
 \
 41
Array aggiornato: 85, 76, 54, 63, 54, 31, 23, 40, 25, 41

A questo punto l’array è un Max-Heap VERIFICATO.
Un array si dice un Max-Heap quando, per ogni nodo i, 
il valore del nodo è maggiore o uguale a quello dei suoi figli. 
In altre parole, la radice dell’albero contiene sempre il massimo valore 
e ogni sottoalbero soddisfa la stessa proprietà.

Fase 2: Ordinamento (estrazione dei massimi)

Si scambia la radice (massimo) con l’ultimo elemento dell’heap e si riapplica MaxHeapify.
Primo passo: 85 ↔ 41
Array: 41, 76, 54, 63, 54, 31, 23, 40, 25, 85

Albero:
          41
       /      \
     76        54
   /   \     /   \
 63    54   31   23
 / \  
40  25
 \
 85
Applico MaxHeapify sulla radice nodo 41 con massimo figlio 76 → scambio 41 ↔ 76
Applico MaxHeapify sul nodo 41: nodo 41 con massimo figlio 63 → scambio 41 ↔ 63
Array: 76, 63, 54, 41, 54, 31, 23, 40, 25, 85

Albero:
          76
       /      \
     63        54
   /   \     /   \
 41    54   31   23
 / \  
40  25
 \
 85
Dopo questo passo, il massimo (85) è in posizione finale.

Il processo si ripete per tutti gli altri elementi fino a ottenere l’array ordinato.
Fase 3: Array ordinato finale
23, 25, 31, 40, 41, 54, 54, 63, 76, 85


*/

/*

1)Introduzione
  Gli algoritmi di ordinamento introdotti finora, come Insertion Sort (IS) e Merge Sort, hanno caratteristiche diverse:
  - Insertion Sort ha tempo di esecuzione O(n^2) nel caso peggiore, ma lavora in-place (utilizza solo una quantità costante di memoria aggiuntiva) ed è efficiente per input piccoli o quasi ordinati.
  - Merge Sort ha tempo di esecuzione O(n log n), ma non è in-place, poiché necessita di memoria aggiuntiva per i sottoarray.

  L’Heapsort, invece, combina i vantaggi di entrambi:
   - Ha complessità O(n log n) in tutti i casi (migliore, medio e peggiore);
   - Lavora su posto, cioè con memoria extra costante;
   - Si basa su una struttura dati detta heap, utilizzata anche per implementare code di priorità.

2)La struttura dati: l’Heap
  Un heap è una rappresentazione parziale di un albero binario completo, memorizzato in un array. 
  L’albero è completo fino al penultimo livello, e l’ultimo può essere parzialmente riempito da sinistra verso destra.

  Ogni nodo A[i] può essere facilmente collegato ai propri figli grazie a relazioni aritmetiche sugli indici:
   parent(i) = floor(i/2)
   left(i) = 2i
   right(i) = 2i + 1

   Esistono due tipi principali di heap:
   - Max-Heap: per ogni nodo i, vale A[i] >= A[parent(i)]; la radice contiene il valore massimo.
   - Min-Heap: per ogni nodo i, vale A[i] <= A[parent(i)]; la radice contiene il valore minimo.

Heapsort utilizza un Max-Heap, perché serve a estrarre progressivamente i valori più grandi per ordinarli in modo crescente.

3)MAX-HEAPIFY
 MAX-HEAPIFY è la procedura fondamentale che mantiene la proprietà di Max-Heap. 
 Dato un nodo i, supponendo che i suoi due sottoalberi sinistro e destro siano già Max-Heap, 
 la funzione controlla se il nodo padre A[i] viola la proprietà del Max-Heap (cioè è minore di uno dei figli).
 Pertanto,se si:
   1. Si trova l’indice del valore massimo tra A[i], A[left(i)] e A[right(i)];
   2. Si scambia il padre con il figlio più grande;
   3. Si richiama ricorsivamente MAX-HEAPIFY sul sottoalbero del figlio, finché la proprietà non è ristabilita.

Complessità di MAX-HEAPIFY
Ogni chiamata di MAX-HEAPIFY può scendere lungo l’albero di un certo numero di livelli, al massimo pari all’altezza dell’heap. 
Poiché un heap di n nodi ha altezza log n, nel caso peggiore l’elemento può "scivolare" fino a una foglia.
Ogni livello richiede un numero costante di operazioni (confronti e swap). Numero massimo di livelli = log n.
Pertanto: T(n) = O(log n).

4)BUILD-MAX-HEAP
  La procedura BUILD-MAX-HEAP trasforma un array non ordinato in un Max-Heap valido. 
  L’idea è partire dal basso dell’albero (dove le foglie sono già heap) e applicare MAX-HEAPIFY a ciascun nodo interno, 
  risalendo fino alla radice.

Complessità di BUILD-MAX-HEAP
A prima vista, poiché MAX-HEAPIFY ha costo O(log n) e viene invocata su circa n/2 nodi, 
si potrebbe pensare che la complessità sia O(n log n). 
Tuttavia, un’analisi più accurata mostra che i nodi più in basso richiedono meno tempo, poiché la loro altezza è minore.

In un heap di n elementi, il numero di nodi ad altezza h è al massimo n / 2^(h+1).
Poiché il costo di MAX-HEAPIFY su un nodo di altezza h è O(h), la somma dei costi totali è:

T(n) <= Sum(h=0 to log n)[n / 2^(h+1) * O(h)]
       = O(n * Sum(h=0 to log n)[h / 2^h])

La serie Sum(h=0 to inf)[h / 2^h] converge a 2, quindi otteniamo:
T(n) = O(n)

In altre parole, la costruzione del Max-Heap richiede tempo lineare, molto più efficiente della stima iniziale O(n log n).
Questo risultato è importante perché spiega l’efficienza di HeapSort nella fase di costruzione dell’heap.

5)HEAPSORT
 Una volta costruito il Max-Heap:
   1. L’elemento massimo si trova nella radice (A[1]);
   2. Si scambia la radice con l’ultimo elemento dell’array;
   3. Si riduce la dimensione effettiva dell’heap di 1 (escludendo l’ultimo elemento, ora al posto corretto);
   4. Si richiama MAX-HEAPIFY sulla radice per ripristinare la proprietà di Max-Heap;
   5. Si ripete il processo finché l’heap contiene solo un elemento.

 Alla fine, l’array è completamente ordinato in modo crescente.

Complessità di HEAPSORT
- Fase 1: Costruzione del Max-Heap → O(n)
- Fase 2: Estrazione e heapify ripetuto → Ogni estrazione costa O(log n) e si ripete n-1 volte: (n-1)*O(log n) = O(n log n)
- Totale complessivo: T(Heapsort)(n) = O(n) + O(n log n) = O(n log n)

Conclusione
Heapsort è un algoritmo di ordinamento efficiente e in-place, ideale quando serve una complessità garantita di O(n log n) 
e non si richiede stabilità.

*/