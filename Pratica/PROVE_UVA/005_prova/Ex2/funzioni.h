#ifndef FUNZIONI_H
#define FUNZIONI_H

typedef struct {
    int n; // Lunghezza totale
    int k; // Numero di barre
    int m; // Massima larghezza di una barra
} BarCode;
 int CalcolaModi(BarCode bc, int unitàRimanenti, int barreRimanenti);

#endif
