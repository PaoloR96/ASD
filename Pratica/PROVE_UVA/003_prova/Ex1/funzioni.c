#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header
int cmpPuntoX(const void *a, const void *b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;

    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    return 0;
}
int cmpPuntoY(const void *a, const void *b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;

    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}
double DistanzaEuclidea(Punto a, Punto b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

double risolvi(Punto P[], int start, int end) {
    // 1. Caso base: un solo punto
    // Non esiste una distanza, quindi restituiamo un valore "infinito"
    if (start == end) return 1e20; 
    // 2. Caso base: due punti
    // Restituiamo la distanza euclidea tra i due
    if (start + 1 == end) return DistanzaEuclidea(P[start], P[end]);
    // 3. Divisione
    int m = (start + end) / 2;
    // Le chiamate ricorsive devono restituire un double (la distanza minima)
    double d_sx = risolvi(P, start, m);
    double d_dx = risolvi(P, m + 1, end);
    // 4. Troviamo il minimo tra le due metà
    double d = (d_sx < d_dx) ? d_sx : d_dx;
    // 5. Striscia centrale:Controlliamo i punti a cavallo della linea di divisione 'm'.
    //Dobbiamo isolare i punti vicini alla linea mediana P[mid].x
    Punto striscia[MAX_PUNTI];
    int contatore = 0;
    for (int i = start; i <= end; i++) {
        // Se la distanza orizzontale dalla mediana è < d, il punto entra!
        if (abs(P[i].x - P[m].x) < d) {
            striscia[contatore++] = P[i];
        }
    }
    //6.La funzione MergeStriscia restituirà il minimo tra 'd' 
    // e le eventuali coppie "miste" trovate nella striscia.
    return MergeStriscia(striscia, contatore, d);; 
}

double MergeStriscia(Punto PuntiInStriscia[], int lunghezzaStriscia, double d_attuale) {
    qsort(PuntiInStriscia, lunghezzaStriscia, sizeof(Punto), cmpPuntoY);//Ordimo in base alla variabile y
    double d_min = d_attuale; 

    for (int i = 0; i < lunghezzaStriscia; i++) {
        for (int j = i + 1; j < lunghezzaStriscia; j++) {        
            // Calcoliamo la differenza verticale (delta Y)
            // Se è già >= d_min, inutile guardare questo punto e i successivi
            if ((PuntiInStriscia[j].y - PuntiInStriscia[i].y) >= d_min) break; 
            // Se arriviamo qui, vale la pena calcolare la distanza vera
            double dist = DistanzaEuclidea(PuntiInStriscia[i], PuntiInStriscia[j]);
            // Se è un nuovo record, lo salviamo
            if (dist < d_min) {
                d_min = dist;
            }
        }
    }
    
    // Restituiamo il minimo assoluto trovato (o quello vecchio se nessuno ha fatto meglio)
    return d_min; 
}