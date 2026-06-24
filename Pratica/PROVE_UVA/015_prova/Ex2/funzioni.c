#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int conteggio=0; // Contatore globale per le sequenze hard trovate

void CalcolaSequenza(char SequenzaK[], int index, int L, int n){
    //1.Condizione di Uscita:se ho raggiunto n
   if(conteggio==n){ 
        StampaSequenza(SequenzaK,index);
        return;
    }
    //2.Ricorsione:testo le prime L lettere
    for (int i = 0; i < L; i++){
            SequenzaK[index] = 'A' + i;//prendo la lettera iesima
            if (IsHard(SequenzaK,index+1)){
                    conteggio++;// Trovata una nuova sequenza Hard
                    CalcolaSequenza(SequenzaK,index+1,L,n);//passo alla successiva
                    //Il BACKTRAKKING avviene il modo automatico, in quanto adrò a valutare l'albero di ricerca 
                    //del mio spazio di input e mi fermerò quando raggiungerò n
                    // if che mi aiuta a fermare la ricorsione evitando di trovare l'elemento n+1 esimo
                if (conteggio == n) return;
            }
    }
}


int IsHard(char SequenzaK[], int lunghezza) {
    // k è la lunghezza della sottosequenza che stiamo confrontando
    // Possiamo controllare k fino a metà della lunghezza totale
    for (int k = 1; k * 2 <= lunghezza; k++) {
        int uguale = 1;
        for (int i = 0; i < k; i++) {
            // Confronta il blocco finale con quello immediatamente precedente
            if (SequenzaK[lunghezza - 1 - i] != SequenzaK[lunghezza - 1 - k - i]) {
                uguale = 0;
                break;
            }
        }
        if (uguale) return 0; //EASY 
    }
    return 1; // HARD
}



// Funzione di stampa 
void  StampaSequenza(char SequenzaK[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (i > 0) {
            if (i % 64 == 0) printf("\n"); // Nuova riga ogni 16 gruppi da 4 
            else if (i % 4 == 0) printf(" "); // Spazio ogni 4 caratteri
        }
        printf("%c", SequenzaK[i]);
    }
    printf("\n%d\n", lunghezza); // Stampa la lunghezza totale 
}