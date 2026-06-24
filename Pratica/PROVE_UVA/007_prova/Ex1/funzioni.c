#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header

// funzione per calcolare la distanza
double distanzaSq(Punto p1, Punto p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
//min
double min(double a, double b) {
    return (a < b) ? a : b;
}
//compare per il qsort
// Funzione di comparazione per qsort (ordina per Y)
int comparaY(const void* a, const void* b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}
// Comparatore per ordinare i punti per coordinata X 
int comparaX(const void* a, const void* b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    return 0;
}

double DistanzaBruta(Punto P[], int start, int end) {
    double minD = 10000.0; // Limite del problema 
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            double d = distanzaSq(P[i], P[j]); // Usa la distanza reale
            if (d < minD) minD = d;
        }
    }
    return minD;
}


double CalcolaSequenza(Punto Coordinata[], int start, int end) {
    //Caso base con soglia a 3 punti
    if (end - start <= 2) return DistanzaBruta(Coordinata, start, end);
    
    //Dividi la sequenza
    int q = (start + end) / 2;
    double midX = Coordinata[q].x; // Salva la X centrale per la striscia
    double dSx = CalcolaSequenza(Coordinata, start, q);
    double dDx = CalcolaSequenza(Coordinata, q + 1, end);
    //trovo la distanza minima
    double delta = min(dSx,dDx);

    // COMBINE: Ispeziona la striscia centrale
    // Passiamo delta per filtrare i punti lontani più di delta dalla linea midX
    double dMista = IspezionaStriscia(Coordinata, start, end, midX, delta);
    return min(delta,dMista);
}

double IspezionaStriscia(Punto Coordinata[], int start, int end, double midX, double delta) {
        Punto striscia[10000]; // Array temporaneo per i punti vicini al confine
        int j = 0;
        // 1. Filtra i punti in base alla distanza X dal centro
        for (int i = start; i <= end; i++) {
            if (fabs(Coordinata[i].x - midX) < delta) {
                striscia[j] = Coordinata[i];
                j++;
            }
        }
        // 2. Ordina i punti della striscia per la coordinata Y 
        qsort(striscia, j, sizeof(Punto), comparaY);
        double minMista = delta;
        // 3. Confronta ogni punto con i successivi (massimo 7)
        for (int i = 0; i < j; i++) {
            for (int k = i + 1; k < j && (striscia[k].y - striscia[i].y) < minMista; k++) {
                double d = distanzaSq(striscia[i], striscia[k]); // Chiamata pulita
                if (d < minMista) minMista = d;
            }
        }
        return minMista;
}






