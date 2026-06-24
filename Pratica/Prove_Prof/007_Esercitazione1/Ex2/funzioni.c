#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/* 
 * METODO 1: INSERIMENTO LISTE (Fase 1)
 * Questo metodo legge l'input delle M liste e popola l'array mappa_colori
 * usando l'approccio ad accesso diretto (Indice = Colore, Valore = ID Lista).
 */
void inserimento_liste(int mappa_colori[], int M) {
    for (int id_lista = 1; id_lista <= M; id_lista++) {
        int Ki; // Numero di colori nella lista corrente
        scanf("%d", &Ki);
        
        for (int j = 0; j < Ki; j++) {
            int colore;
            scanf("%d", &colore);
            
            // Il colore diventa l'indice dell'array (inserimento non sequenziale)
            mappa_colori[colore] = id_lista;
        }
    }
}
/* 
 * METODO 2: CALCOLO SEGMENTI (Fase 2)
 * Questo metodo legge la sequenza lunga L, consulta l'array mappa_colori
 * e restituisce il numero totale di segmenti distinti che Batman riesce a vedere.
 */
int calcola_segmenti(int mappa_colori[], int L) {
    int segmenti = 1; // C'è sempre almeno un segmento iniziale
    int colore_corrente;
    
    // Leggiamo il primo colore per stabilire il punto di partenza
    scanf("%d", &colore_corrente);
    int lista_precedente = mappa_colori[colore_corrente];
    
    // Ciclo per i restanti L-1 colori della sequenza
    for (int i = 1; i < L; i++) {
        scanf("%d", &colore_corrente);
        int lista_corrente = mappa_colori[colore_corrente];
        
        // Se il colore appartiene a una lista diversa dal precedente, c'è uno stacco
        if (lista_corrente != lista_precedente) {
            segmenti++;
            lista_precedente = lista_corrente; // Aggiorniamo il precedente
        }
    }
    
    return segmenti; // Restituisce il risultato numerico
}