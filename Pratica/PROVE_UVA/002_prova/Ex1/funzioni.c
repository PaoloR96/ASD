#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Funzione di fusione
// Unisce lo skyline sx e lo skyline dx nell'array res
int merge(Punto sx[], int n_sx, Punto dx[], int n_dx, Punto res[]) {
    int i = 0, j = 0, k = 0;
    int h1 = 0, h2 = 0;

    while (i < n_sx && j < n_dx) {
        int x_attuale;
        // 1. Scegliamo la coordinata x minore 
        if (sx[i].x < dx[j].x) {
            x_attuale = sx[i].x;
            h1 = sx[i].h;
            i++;
        } else if (sx[i].x > dx[j].x) {
            x_attuale = dx[j].x;
            h2 = dx[j].h;
            j++;
        } else {
            x_attuale = sx[i].x;
            h1 = sx[i].h;
            h2 = dx[j].h;
            i++; j++;
        }
        // 2. L'altezza dello skyline fuso è il massimo tra le due 
        int h_max = (h1 > h2) ? h1 : h2;
        // 3. Aggiungiamo il punto solo se l'altezza cambia 
        if (k == 0 || res[k-1].h != h_max) {
            res[k].x = x_attuale;
            res[k].h = h_max;
            k++;
        }
    }
    // Copia i punti rimanenti
    while (i < n_sx) res[k++] = sx[i++];
    while (j < n_dx) res[k++] = dx[j++];
    return k;
}

// Funzione ricorsiva corretta con parametro edifici
int risolvi(int edifici[][3], int inizio, int fine, Punto risultato[]) {
    // CASO BASE: Un solo edificio
    if (inizio == fine) {
        // Un edificio (L, H, R) genera due punti critici nello skyline 
        risultato[0].x = edifici[inizio][0]; // Coordinata x sinistra (L) 
        risultato[0].h = edifici[inizio][1]; // Altezza dell'edificio (H) 
        risultato[1].x = edifici[inizio][2]; // Coordinata x destra (R) 
        risultato[1].h = 0;                  // L'altezza torna a 0 dopo R 
        return 2;
    }
    int meta = inizio + (fine - inizio) / 2;
    // Array temporanei per i risultati dei sotto-problemi
    Punto sx[MAX_PUNTI]; 
    Punto dx[MAX_PUNTI];
    // Chiamate ricorsive passando l'array degli edifici
    int n_sx = risolvi(edifici, inizio, meta, sx);
    int n_dx = risolvi(edifici, meta + 1, fine, dx);
    // Fusione (Merge) dei due skyline parziali 
    return merge(sx, n_sx, dx, n_dx, risultato);
}