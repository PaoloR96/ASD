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
//////////////////////////metodo Insert
void InsertSort(int A[],int size){
    
    for(int j=1;j<size;j++){                                //c1*n
        int key=A[j];                                       //c2*(n-1)
        int i=j-1;                                          //c3*(n-1)
        while(i>=0 && A[i]>key){                            //c4*{SUM[j=2 to size]*(tj)}
            A[i+1]=A[i];                                    //c5*{SUM[j=2 to size]*(tj-1)}
            i--;                                            //c6*{SUM[j=2 to size]*(tj-1)}
        }
        A[i+1]=key;                                         //c7*(n-1)
    }

}


/*
Calcolo della complessità
T(n)=c1*n+(c2+c3+c7)*(n-1)+c4*{SUM[j=2 to size]*(tj)}+(c5+c6)*{SUM[j=2 to size]*(tj-1)}

1)Best Case:Non entro nel ciclo while,quindi l'array è già ordinato:
  T(n)=c1*n+(c2+c3+c7)*(n-1)=>O(n)
  il tempo cresce in maniera lineare con la dimensione del vettore da ordinare;

2)Worst Case: vettore ordinato in senso inverso:
  {SUM[j=2 to size]*(tj)}=>[n*(n-1)]/2
  T(n)=c1*n+(c2+c3+c7)*(n-1)+c4*{[n*(n-1)]/2}+(c5+c6)*{([n*(n-1)]/2)-1} ===>dai calcoli avrò:
  
  T(n)=an^2 + bn + c ==>O(n^2)
  il tempo di esecuzione cresce col quadrato della lunghezza n del vettore

*/

/*
Supponiamo di voler ordinare il seguente array in ordine crescente:
A = [5, 2, 4, 6, 1, 3]

Passo 1:
key = 2, confronto con 5 → 2 < 5
→ sposto 5 a destra → A = [5, 5, 4, 6, 1, 3]
→ inserisco la key → A = [2, 5, 4, 6, 1, 3]

Passo 2:
key = 4, confronto con 5 → 4 < 5
→ sposto 5 → A = [2, 5, 5, 6, 1, 3]
→ confronto con 2 → 4 > 2, quindi inserisco → A = [2, 4, 5, 6, 1, 3]

Passo 3:
key = 6, confronto con 5 → 6 > 5, non serve spostare nulla → A = [2, 4, 5, 6, 1, 3]

Passo 4:
key = 1, confronto con 6, 5, 4, 2 → tutti maggiori → li sposto a destra
→ infine inserisco 1 in posizione 0 → A = [1, 2, 4, 5, 6, 3]

Passo 5:
key = 3, confronto con 6, 5, 4, 2 → solo 6, 5, 4 sono maggiori
→ li sposto → A = [1, 2, 4, 4, 5, 6]
→ inserisco 3 → A = [1, 2, 3, 4, 5, 6]

Alla fine, l’array risulta completamente ordinato.
*/
/*Parto con il ciclo for dall’indice 1, perché l’elemento in posizione 0 può essere considerato, 
di per sé, già ordinato.
Imposto quindi key = A[1], cioè l’elemento che voglio inserire nella giusta posizione, 
e definisco i = 1 - 1 = 0.
Confronto la key con A[i].
Se A[i] è maggiore della key, sposto A[i] una posizione in avanti (A[i + 1] = A[i]) 
e decremento i per continuare a confrontare con gli elementi precedenti.
Il ciclo while continua finché i è maggiore o uguale a zero e A[i] è maggiore della key.
Quando una di queste condizioni non è più verificata (cioè i < 0 oppure A[i] ≤ key), 
inserisco la key nella posizione corretta: A[i + 1] = key.
Ripetendo questo procedimento per tutti gli elementi, 
la parte sinistra dell’array diventa progressivamente ordinata, 
fino a ordinare l’intero vettore.*/

