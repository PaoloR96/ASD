#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdbool.h>

void StampaMatrice(int N, int A[][N]);
bool CheckColonna(int N, int A[][N],int colonna);
bool CheckDiagonale(int N, int A[][N], int riga, int colonna);
void CheckNRegine(int N, int A[][N],int riga);
void TrovaSoluzioni(int i,int N);

#endif
