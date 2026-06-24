#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Array necessario per collegare la posizione nella sequenza al blocco ID
int mappa_id[MAX];
int albero[4 * MAX]; 

int CreazioneMappa(Blocco *B, int Input[MAX], int dim){
    //1.Inserisco il primo elemento
    int index = 0;
    B[index].id = index;
    B[index].valore = Input[0];
    B[index].start = 0;
    B[index].freq = 1;
    mappa_id[0] = 0; 

    //2.Aggiungo gli altri
    for (int i = 1; i < dim; i++){
        if (Input[i] == B[index].valore){
            B[index].freq++;
        } else {
            B[index].end = i - 1;
            index++;
            B[index].id = index;
            B[index].valore = Input[i];
            B[index].start = i;
            B[index].freq = 1;
        }
        mappa_id[i] = index; // Ad ogni passo salviamo a quale blocco appartiene i
    }
    // chiusura ultimo blocco
    B[index].end = dim - 1;
    return index; // Restituisce l'ultimo ID creato
}

int CalcolaQuery(Blocco *B, int Sequenza[MAX], int start, int end, int ultimo_id) {
    // Trasformiamo gli indici della query (1-based) in 0-based
    int i = start - 1;
    int j = end - 1;

    // Recuperiamo i blocchi corretti usando la mappa_id
    int id_i = mappa_id[i];
    int id_j = mappa_id[j];

    // CASO 1: La query è contenuta interamente nello stesso blocco
    if (id_i == id_j) return j - i + 1;

    // CASO 2: La query attraversa più blocchi
    // 1. Calcola la frequenza della Testa
    int freq_testa = B[id_i].end - i + 1;

    // 2. Calcola la frequenza della Coda
    int freq_coda = j - B[id_j].start + 1;

    // 3. Calcola il massimo tra i blocchi centrali completi
    int freq_centro = 0;
    if (id_j > id_i + 1) {
        // Chiamata alla funzione RMQ passata come parametro
        freq_centro = querySegmentTree(1, 0, ultimo_id, id_i + 1, id_j - 1);
    }

    // Restituisci il massimo tra i tre risultati
    int max_parziale = (freq_testa > freq_coda) ? freq_testa : freq_coda;
    return (freq_centro > max_parziale) ? freq_centro : max_parziale;
}

int max_val(int a, int b) {
    return (a > b) ? a : b;
}

int querySegmentTree(int nodo, int inizio, int fine, int l, int r) {
    if (r < inizio || fine < l) return -1;
    if (l <= inizio && fine <= r) return albero[nodo];
    
    int mid = (inizio + fine) / 2;
    int p1 = querySegmentTree(2 * nodo, inizio, mid, l, r);
    int p2 = querySegmentTree(2 * nodo + 1, mid + 1, fine, l, r);
    
    return max_val(p1, p2);
}

void buildSegmentTree(Blocco *B, int nodo, int inizio, int fine) {
    if (inizio == fine) {
        albero[nodo] = B[inizio].freq;
        return;
    }
    int mid = (inizio + fine) / 2;
    buildSegmentTree(B, 2 * nodo, inizio, mid);
    buildSegmentTree(B, 2 * nodo + 1, mid + 1, fine);
    albero[nodo] = max_val(albero[2 * nodo], albero[2 * nodo + 1]);
}