#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

// Costanti
#define N 4       // numero di oggetti
#define S 7       // capacità massima dello zaino

// Matrice DP globale
extern int DP[N+1][S+1];

// Definizione struttura oggetto
typedef struct {
    int peso;
    int valore;
} Oggetto;

// Prototipi funzioni
void InizializzaDp();
void CostruisciDP(Oggetto zaino[]);
void StampaDP();

#endif