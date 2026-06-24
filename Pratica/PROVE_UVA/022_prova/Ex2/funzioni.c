#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header
bool trovato;
void TrovaSequenza(int m,int n, int Catena[],int k){
    //1.Ho creato la sequenza
    if(trovato)return;
    //2.Controllo se rispetta le mie due condizioni:
    //2.1 Ho raggiunto la profondità m?
    if (k==m){
            //2.2 l'ultimo elemento è uguale a n
            if (Catena[k-1]==n){
                StampaSequenza(Catena,k);
                trovato=true;
            }            
            return;
    }

    //3.Controllo:Se raddoppiando l'ultimo elemento per i passi rimanenti non arrivi a n, pota il ramo
    long long max_val = Catena[k-1];
    for (int p = 0; p < (m - k); p++) max_val *= 2;
    if (max_val < n) return;

    //4.Genero la sequenza
    //Parto a ritroso in modo tale da ottenere numeri grandi che tendono ad avvicinarsi alla sequnza con
    //meno passo possibili
    for (int i = k-1; i >=0 ; i--){
        int ak=Catena[i];
        //per ogni ak lo sommo con gli aj presenti nella catena
        for (int j = i; j>=0; j--){
            int aj=Catena[j];
            int Somma=ak+aj;
            if (Somma<=n && Somma>Catena[k-1]){
                    Catena[k] = Somma;
                    TrovaSequenza(m, n, Catena, k + 1);//passo al k successivo
                    if (trovato) return; // Se trovata nei rami successivi, esci subito
                    /*
                    Il backtracking avviene in modo automatico attraverso la ricorsione: quando un ramo non porta alla soluzione, 
                    la funzione 'torna su' per esplorare strade alternative. 
                    */
            }
            /*
            Il pruning interviene invece interrompendo preventivamente l'esplorazione di un ramo che, 
             essendo teoricamente valido, non può matematicamente portare alla soluzione minima o al target richiesto
            */
        }
    }
}

void StampaSequenza(int Catena[MAX], int dim) {
    for (int i = 0; i < dim; i++) {
       printf("%d%s", Catena[i], (i == dim - 1 ? "" : " "));
    }
    printf("\n");
}