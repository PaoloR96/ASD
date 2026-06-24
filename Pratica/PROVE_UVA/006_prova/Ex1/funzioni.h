#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX 5001
// Il numero massimo di coppie per N=5000 è (5000 * 4999) / 2 = 12.497.500
#define MAX_COPPIE 12500000 

typedef struct {
    int x, y;
} Punto;

typedef struct {
    int y1, y2;
} CoppiaY;

int confrontaPunti(const void *a, const void *b);
int GeneraTutteLeCoppie(Punto punti[], int n, CoppiaY tutteLeCoppie[]);
int ContaRettangoli(CoppiaY tutteLeCoppie[], int totaleCoppie);

#endif