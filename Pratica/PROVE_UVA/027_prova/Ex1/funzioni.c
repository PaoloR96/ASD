#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int calcolaCapacitaMinima(int n, int m, int vasi[MAX]){
    int low=0;
    int high=0;
    // Inizializzazione dei limiti
    for(int i = 0; i < n; i++) {
        if(vasi[i] > low) low = vasi[i]; // Il minimo deve contenere il vaso più grande 
        high += vasi[i];                // Il massimo è la somma di tutti i vasi
    }
    int risultato=high;
    while (low<=high){
            int mid = low + (high - low) / 2;
            if (PossoDistribuire(n,m,mid,vasi)){
                //Posso trovare un valore più piccolo
                risultato=mid;//salvo la capacità attuale ma potrei trovare di meglio
                high=mid-1;
            }else{
                //Troppo piccola, aumento la capacità
                low=mid+1;
            }
    }
    return risultato;
}
bool PossoDistribuire(int n, int m, int capacitaMax, int vasi[]){
        int contenitoriUsati = 1;
        int caricoAttuale = 0;
        for (int i = 0; i < n; i++){
            // Se un singolo vaso supera la capacità (mid), è impossibile
            if(vasi[i]>capacitaMax)return false;
            
            if (caricoAttuale+vasi[i]<=capacitaMax){
                // Il vaso sta nel contenitore attuale
                caricoAttuale+=vasi[i];
            }else{
                contenitoriUsati++;
                caricoAttuale = vasi[i];
            }
        }
        if(contenitoriUsati<=m)return true;
        return false;
}