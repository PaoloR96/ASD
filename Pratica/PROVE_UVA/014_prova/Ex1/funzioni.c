#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
// Inizializzazione delle variabili esterne
int mappa[DIM][DIM];
char stringa[2048];
int indice;
void elabora_quadtree(int r, int c, int w) {
    // Legge il carattere corrente (p, f, o e)
    char nodo = stringa[indice++];
    //CASO1: leggo p
    if (nodo == 'p') {
        // DIVIDI: Il nodo è un genitore, scendi di un livello
        int meta=w/2;
        elabora_quadtree(r, c + meta, meta);     // 1: Alto Destra
        elabora_quadtree(r, c, meta);            // 2: Alto Sinistra
        elabora_quadtree(r + meta, c, meta);     // 3: Basso Sinistra
        elabora_quadtree(r, c+meta, meta);     // 4: Basso Destra
    }else if(nodo=='f'){ //CASO2: leggo f
        //Il quadrante è nero:riempi la porzione corrispondente della matrice
        for (int i = r; i < r + w; i++) {
            for (int j = c; j < c + w; j++) {
                mappa[i][j] = 1; 
            }
        }
    }
    //CASO3:Quadrante bianco, non facciamo nulla,resta 0
}