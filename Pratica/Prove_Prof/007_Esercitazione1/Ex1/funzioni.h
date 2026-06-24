#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <stdbool.h>
#define  MAX 100
/*VAR GLOBALE*/
extern int Contatore;
/*Metodi*/
void PosizionaRegina(int Viseted[MAX][MAX],int riga,int N);
bool IsSicuro(int Viseted[MAX][MAX], int riga, int colonna, int N);
#endif
