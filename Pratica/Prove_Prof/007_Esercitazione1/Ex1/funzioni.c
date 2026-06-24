#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header
/*var globale*/
int Contatore=0;
void PosizionaRegina(int Viseted[MAX][MAX],int riga,int N){
    //Condizione di uscita:Ho posizionato tutte le regine
    if(riga==N){
        Contatore++;
        return;
    }
    //Ricorrenza
    for (int c = 0; c < N; c++){//per ogni colonna c
        if(IsSicuro(Viseted,riga,c,N)){
            Viseted[riga][c]=1;//Provo a piazzare la regina
            PosizionaRegina(Viseted,riga+1,N);//Passo a livello successivo 
            Viseted[riga][c]=0;//BACKTACKING
        }
    }
}


bool IsSicuro(int Viseted[MAX][MAX], int riga, int colonna, int N) {
    // Controllo 1: Verifico se sono sulla stessa colonna 
    //Potrei mettere anche N ma usando riga verifico fino alla riga corrente in modo tale da risparmiare cicli
    for (int r = 0; r < riga; r++) {
        if (Viseted[r][colonna] == 1) return false;//Posizione occupata
    }
    
    // Controllo 2: Verifico se sono sulla stessa diagonale principale
    int r = riga;
    int c = colonna;
    while (r >= 0 && c >= 0) {
        if (Viseted[r][c] == 1) return false;//Posizione occupata
        r--;
        c--;
    }
    
    // Controllo 3: Verifico se sono sulla stessa diagonale secondaria
    r = riga;   
    c = colonna;  
    while (r >= 0 && c < N) {
        if (Viseted[r][c] == 1) return false;//Posizione occupata
        r--;
        c++;
    }
    //Posizione libera
    return true;
}