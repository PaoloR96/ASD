#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

// Costanti
#define DIM_X 6
#define DIM_Y 7

// Variabile globale
extern int DP[DIM_X+1][DIM_Y+1];

// Funzioni
void InizializzaDp();
void CalcolaLCS(char x[], char y[]);
void StampaDP(char x[], char y[]);

#endif