#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

// Riempie le differenze tra i pioli
void RiempiCasoTest(int Dh[MAX], int dim) {
    int precedente = 0;
    int attuale;
    for (int i = 0; i < dim; i++) {
        scanf("%d", &attuale);
        Dh[i] = attuale - precedente; // Calcola il salto necessario
        precedente = attuale;
    }
}
// Verifica se un dato k permette di arrivare in cima 
int SimulaSalto(int Dh[MAX], int dim, int k) {
    for (int i = 0; i < dim; i++) {
        if (Dh[i] > k) return 0;      // Salto impossibile 
        if (Dh[i] == k) k--;          // La forza cala 
        // Se Dh[i] < k, k resta invariato
    }
    return 1; 
}

int TrovaMax(int Dh[MAX], int dim) {
    int max = Dh[0];
    for (int i = 1; i < dim; i++) {
        if (Dh[i] > max) max = Dh[i];
    }
    return max;
}


int RicercaBinariaK(int Dh[MAX],int dim){
        int low = TrovaMax(Dh, dim);
        int high = 10000000; // Altezza massima possibile
        int ans = high; //variabile per tener traccia del k minimo
        while (low<=high){
            int mid = low + (high - low) / 2;
            int Esito=SimulaSalto(Dh,dim,mid);
            if(Esito){
                ans = mid;       // Questo k funziona, salviamolo
                high = mid - 1;  // Proviamo se esiste un k più piccolo
            }else{
                low=mid+1;       // k troppo piccolo, dobbiamo aumentare      
            }
        }
        return ans;
}
