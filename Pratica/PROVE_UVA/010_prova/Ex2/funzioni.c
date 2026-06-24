#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
#include <stdio.h>

void stampaMosse(Posizione mosse[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c%d   %c%d\n",mosse[i].start_col,mosse[i].start_row,mosse[i].end_col,mosse[i].end_row);
    }
}

// Converte una lettera minuscola della colonna in numero (a-h -> 1-8)
int LetteraInNumero(char lettera) {
    if(lettera >= 'a' && lettera <= 'h') {
        return (lettera - 'a' + 1);
    } else {
        return -1; // valore non valido
    }
}

// Converte un numero in lettera minuscola della colonna (1-8 -> a-h)
char NumeroInLettera(int numero) {
    if(numero >= 1 && numero <= 8) {
        return 'a' + (numero - 1);
    } else {
        return '?'; // valore non valido
    }
}


// Funzione che calcola la iesima mossa del cavallo
Coppia calcolaMossa(int x, int y, int indice) {
    Coppia risultato;

    switch(indice) {
        case 1:
            risultato.x = x + 2;
            risultato.y = y + 1;
            break;
        case 2:
            risultato.x = x + 2;
            risultato.y = y - 1;
            break;
        case 3:
            risultato.x = x - 2;
            risultato.y = y + 1;
            break;
        case 4:
            risultato.x = x - 2;
            risultato.y = y - 1;
            break;
        case 5:
            risultato.x = x + 1;
            risultato.y = y + 2;
            break;
        case 6:
            risultato.x = x + 1;
            risultato.y = y - 2;
            break;
        case 7:
            risultato.x = x - 1;
            risultato.y = y + 2;
            break;
        case 8:
            risultato.x = x - 1;
            risultato.y = y - 2;
            break;
        default:
            // Indice non valido, ritorniamo (-1, -1)
            risultato.x = -1;
            risultato.y = -1;
    }

    return risultato;
}

// Funzione che verifica se la mossa è valida sulla scacchiera 8x8
int MossaValida(Coppia mossa) {
    if(mossa.x >= 1 && mossa.x <= 8 && mossa.y >= 1 && mossa.y <= 8) {
        return 1; // valida
    } else {
        return 0; // non valida
    }
}


// Verifica se la coordinata è già presente nel percorso attuale
int GiaVisitata(Coppia mossa, Percorso ListaMosse[], int n) {
    for (int j = 0; j < n; j++) {
        // Convertiamo la lettera salvata nel percorso in numero per il confronto
        if (LetteraInNumero(ListaMosse[j].start) == mossa.x && ListaMosse[j].end == mossa.y) {
            return 1; // Trovata: la casella è già stata visitata
        }
    }
    return 0; // Non trovata
}




/*Variabile globale*/
int recordMin;

void TrovaPercorso(Posizione mossax, Coppia mossaAtt, Percorso ListaMosse[], int cont) {
    // Caso 1: Destinazione raggiunta
    if (mossaAtt.x == LetteraInNumero(mossax.end_col) && mossaAtt.y == mossax.end_row) {
        if (cont < recordMin) {
            recordMin = cont;
        }
        return;
    }

    // Caso 2: (Pruning): senza di essa entrerei in un loop
    if (cont >= recordMin || cont > 6) return;

    // Ricorsione
    for (int i = 1; i <= MAX_MOSSE; i++) {
        // Calcolo la mossa partendo dalla posizione ATTUALE (mossaAtt)
        Coppia prossimaMossa = calcolaMossa(mossaAtt.x, mossaAtt.y, i);

        // Se la mossa è valida sulla scacchiera
        if (MossaValida(prossimaMossa)) {
            
            // Se la posizione non è stata già visitata
            if (!GiaVisitata(prossimaMossa, ListaMosse, cont)) {
                
                // Salvo la mossa nel percorso attuale per i controlli dei rami futuri
                ListaMosse[cont].start = NumeroInLettera(prossimaMossa.x);
                ListaMosse[cont].end = prossimaMossa.y;
                ListaMosse[cont].index = cont;

                // Chiamata ricorsiva con la nuova coordinata
                TrovaPercorso(mossax, prossimaMossa, ListaMosse, cont + 1);
            }
        }
    }
}