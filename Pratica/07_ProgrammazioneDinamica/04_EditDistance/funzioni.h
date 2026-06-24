#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>  // per INT_MAX

// Costanti
#define DIM_X 9    // "alghoritm" ha 9 caratteri
#define DIM_Y 10   // "altruistic" ha 10 caratteri

// Variabili globali
extern int DP[DIM_X+1][DIM_Y+1];   // matrice DP

// Funzioni
void InizializzaDp();
void StampaDP(char x[DIM_X], char y[DIM_Y]);
void EditDistance(char x[DIM_X], char y[DIM_Y]);
int min3(int a, int b, int c);

#endif