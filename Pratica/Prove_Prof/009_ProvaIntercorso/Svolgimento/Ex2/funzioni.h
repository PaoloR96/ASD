#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
#include <stdbool.h>
/*Metodi*/
bool IsPrimo(int n);
void CalcolaSequenza(int Insieme[], int S, int N, int P, int index, int sommaParziale);
void StampaSequenza(int Insieme[MAX],int dim);
#endif
