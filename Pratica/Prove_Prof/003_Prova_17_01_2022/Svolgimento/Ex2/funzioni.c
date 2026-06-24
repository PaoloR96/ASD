#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int TrovaPosizioneMAX(int V[MAX], int dim) {
    int pos = 0;
    int max = V[0]; //Setto come Max il primo elemento
    for (int i = 1; i < dim; i++) { // Parti a controllare i restanti
        if (V[i] > max) {
            pos = i;
            max = V[i];
        }
    }
    return pos;
}
void Swap(int *a, int *b){
    int tmp=0;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void Flip(int k, int V[MAX]) {
    int i = 0;    // Parti sempre dalla cima (sinistra)
    int j = k;    // Arrivi fino all'indice k
    while (i < j) {
        //Scambio (0,k),(1,k-1) ecc......
        Swap(&V[i], &V[j]);
        i++;
        j--;
    }
}

NumeroFlip CalcolaNumeroFlip(int V[MAX],int dim){
    NumeroFlip r;
    //Copio i valori V nella struct r (in modo tale che con il return avrò valori e numero di flip)
    for(int j = 0; j < dim; j++) r.Vettore[j] = V[j];
    int index=0;
    // 1. Ciclo esterno: 'i' rappresenta la dimensione della "sotto-pila" non ancora ordinata
    for (int i = dim; i >=2; i--){
       //2.Trova l'indice (0 to i-1) del massimo nella sotto-pila attuale
        int indiceMax = TrovaPosizioneMAX(V, i);
        // Se l'indice del massimo NON è già l'ultimo della sotto-pila (i-1)
        if (indiceMax != i - 1) {//NOTA:Con questa condizione eviterò di fare cicli inutili
            //2.A:Se il massimo non è in cima (indice 0), portalo in cima
            if (indiceMax != 0) {
                Flip(indiceMax, V);
                r.F[index]=dim - indiceMax;//Salvo la posizione del flip
                index++;
            }        
            //2.B.Ora il massimo è in cima, lo ribaltiamo fino all'indice i-1
            Flip(i-1, V);
            r.F[index]=dim - (i - 1); // Salvo la posizione del flip
            index++;
        }
    }
    r.F[index]=0;//chiudo la sequenza
    return r;
}