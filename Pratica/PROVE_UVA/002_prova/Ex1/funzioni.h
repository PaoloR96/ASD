#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_EDIFICI 5005
#define MAX_PUNTI 10010
typedef struct {
    int x;
    int h;
} Punto;
/*Metodi*/
int merge(Punto sx[], int n_sx, Punto dx[], int n_dx, Punto res[]);
int risolvi(int edifici[][3], int inizio, int fine, Punto risultato[]);

#endif
