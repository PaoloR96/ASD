#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header

void RiempiCasiTest(int S[R]){
    for (int i = 0; i < R; i++)scanf("%d",&S[i]);
}


int Compara(int S[R], int P[R]) {
    int mosse = 0;
    for(int i = 0; i < R; i++) {
        if(S[i] != P[i]) mosse++; // Se la riga è diversa, conta 1 mossa [cite: 8]
    }
    return mosse;
}


bool controlliVerificati(int posizioneRegina[], int colonna, int riga) {
    for (int i = 0; i < colonna; i++) {
        // 1. Controllo riga (Orizzontale)
        if (posizioneRegina[i] == riga) 
            return false;
        
        // 2. Controllo Diagonali (Differenza assoluta)
        if (abs(posizioneRegina[i] - riga) == abs(i - colonna)) 
            return false;
    }
    return true; // Nessun conflitto trovato
}





// Inizializza con il valore massimo possibile (8 regine da spostare)
int MinimoGlobale = 8;
void PosizioneRegina(int Sequenza[R],int posizioneRegina[R],int colonna){
        //1. Condizione di uscita:Riempito il vettore posizione
        if(colonna==R){
            //Comparo il vettore generato  dal backtrakking con la mia Sequenza e contro il numero di mosse
             int numeroMosse=Compara(Sequenza,posizioneRegina);
             if(numeroMosse<MinimoGlobale)MinimoGlobale=numeroMosse;
             return; //esco dalla ricorsione
        }

        //2.Ricorrenza:Prova tutte le righe per la colonna attuale
        for (int riga = 1; riga <= R; riga++){
             if(controlliVerificati(posizioneRegina,colonna,riga)){
                posizioneRegina[colonna]=riga; //posiziono la regina
                PosizioneRegina(Sequenza,posizioneRegina,colonna+1);//passo alla colonna successiva
                //backtrakking :avviene automaticamente sovrascrivendo posizioneRegina[colonna] al prossimo ciclo
             }
        }
}



