#ifndef FUNZIONI_H
#define FUNZIONI_H
// L'immagine è 32x32 unità
#define DIM 32
// Matrice globale per memorizzare i pixel neri (1) e bianchi (0)
extern int mappa[DIM][DIM];
// Stringa per la rappresentazione pre-order e indice globale per la scansione
extern char stringa[2048];
extern int indice;
/*Metodi*/
void elabora_quadtree(int r, int c, int w);
#endif
