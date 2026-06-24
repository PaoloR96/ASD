#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdbool.h>

#define MAX 5

typedef struct {
    int x;
    int y;
} Coordinate;

// La variabile globale per il risultato
extern int minMosseGlobal;

// Dichiarazione della scacchiera obiettivo
extern const int ScacchieraTarget[MAX][MAX];

/* Metodi */
Coordinate TrovaPosizioneLibera(int M[MAX][MAX]);
void CalcolaNumeroMinSequenze(int M[MAX][MAX], int rigaAtt, int colonnaAtt, int mosseFatte);
int contaDifferenze(int M[MAX][MAX]);
void Swap(int *a, int *b);
bool PosizioneValida(int r, int c);
void RiempiMatrice(int M[MAX][MAX]);

#endif