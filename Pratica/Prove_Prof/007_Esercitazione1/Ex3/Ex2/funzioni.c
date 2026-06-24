#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*var globali*/
int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int W[MAX][MAX],int NumColonne,int NumRighe){
    for (int i = 0; i < NumRighe; i++){
        for (int j = 0; j < NumColonne; j++) DP[i][j] = 0;
    }
    //Inizializzo la DP:Ragiono a ritroso,ossia parto dal punto di fine
    //pertanto inizializzo dp in funzione dei valori presenti nell'ultima colonna 
    int ultimaColonna = NumColonne - 1;
    for (int i = 0; i < NumRighe; i++)DP[i][ultimaColonna]=W[i][ultimaColonna];
}
void CalcolaDP(int DP[MAX][MAX],int W[MAX][MAX],int numRighe,int numColonne){
    // Si parte dalla PENULTIMA colonna (numColonne - 2) e si va a ritroso fino alla colonna 0
    for (int c =numColonne-2 ; c >=0; c--){
        for (int r = 0; r < numRighe; r++){
            /*
            Per ogni riga e colonna, il valore DP[r][c] è dato:
            1)Peso W[r][c]
            2)valore assocaito alla diagonale superiore
            3)valore assocaito alla diagonale inferiore
            4)valore assocaito alla posizione adiacente 
            */ 
            // Gestione del cilindro (wrapping delle righe)
            int rigaSu=(r-1+numRighe)%numRighe;
            int rigaGiu=(r+1)%numRighe;
            DP[r][c]=W[r][c]+min2(DP[rigaSu][c+1],DP[rigaGiu][c+1],DP[r][c+1]);
        }   
    }
}

int min2(int a,int b,int c){
    int minimo = a;
    if (b < minimo) minimo = b;
    if (c < minimo) minimo = c;
    return minimo;
}

void ElaboraPercorso(int DP[MAX][MAX],int numRighe,int numColonne){
    int Percorso[MAX];
    int index=0;
    //1.Trova la riga di partenza ottimale guardando la colonna 0
    int rigaCorrente = TrovaIlMinimo(DP, 0, numRighe);
    Percorso[index++] = rigaCorrente + 1; // +1 perché l'output richiede righe da 1 a M
    //2.Ricostruzione del cammino andando da sinistra a destra
    for (int colonne = 0; colonne < numColonne-1; colonne++){
            int rigaSu=(rigaCorrente-1+numRighe)%numRighe;
            int rigaGiu=(rigaCorrente+1)%numRighe;
            int rigaStessa=rigaCorrente;
            //3.Dobbiamo capire quale delle tre scelte ha generato il valore minimo in DP
            int vSu=DP[rigaSu][colonne+1];
            int vStessa=DP[rigaStessa][colonne+1];
            int vGiu=DP[rigaGiu][colonne+1];
            int ValoreScelto=min2(vSu,vStessa,vGiu);
            //4.Applichiamo la regola lessicografica: a parità di valore, 
            // scegliamo la riga con l'indice numerico più basso (es. riga 1 preferita a riga 5)
           int prossimaRiga = TrovaRiga(ValoreScelto, vGiu, vStessa, vSu, rigaSu, rigaStessa, rigaGiu, numRighe); // Inizializzo con un valore alto non valido
            
            //Aggiorno i parametri
            rigaCorrente=prossimaRiga;
            Percorso[index++] = rigaCorrente + 1;
    }
    // Stampa del percorso trovato
    for (int i = 0; i < numColonne; i++) {
        printf("%d ", Percorso[i]);
    }
    printf("\n");
    
}


// Trova l'indice della riga che ha il valore minimo in una determinata colonna
int TrovaIlMinimo(int DP[MAX][MAX], int colonna, int numRighe) {
    int rigaMin = 0;
    for (int i = 1; i < numRighe; i++) {
        if (DP[i][colonna] < DP[rigaMin][colonna]) rigaMin = i;//In questo modo confronto il min trovato con il prossimo valore della riga
        
    }
    return rigaMin;
}


int TrovaRiga(int ValoreScelto, int VGiu, int Vstessa, int Vsu, int rigaSu, int rigaStessa, int rigaGiu, int numeroRighe) {
    int prossimaRiga = -1;
    
    for (int r = 0; r < numeroRighe; r++) {
        // Controlliamo in ordine di riga (0, 1, 2...) 
        // confrontando l'indice 'r' con la riga di destinazione e il suo valore DP con ValoreScelto
        if (r == rigaSu && Vsu == ValoreScelto) {
            prossimaRiga = r;
            break;
        }
        if (r == rigaStessa && Vstessa == ValoreScelto) {
            prossimaRiga = r;
            break;
        }
        if (r == rigaGiu && VGiu == ValoreScelto) {
            prossimaRiga = r;
            break;
        }
    }
    
    return prossimaRiga;
}