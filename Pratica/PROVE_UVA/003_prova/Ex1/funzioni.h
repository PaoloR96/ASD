#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_PUNTI 10000
//creo la struttura punto
typedef struct {
    /* data */
    int x;
    int y;
}Punto;
/*Prototipi funzione*/
//Ordinamento coordinate (X,Y)
int cmpPuntoX(const void *a, const void *b);
int cmpPuntoY(const void *a, const void *b);
//Calcolo distanza Euclidea
double DistanzaEuclidea(Punto a, Punto b);
//Applico il Merge
double risolvi(Punto P[], int start, int end);
double MergeStriscia(Punto PuntiInStriscia[], int lunghezzaStriscia, double d_attuale);

#endif
