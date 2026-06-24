#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <stdbool.h>
#define MAX 100
extern int MaxPercorsoGlobale;
void TrovaLunghezzaPercorso(int Matrice[MAX][MAX],int N,int M,int x,int y,int lunghezza);
bool IsSafe(int Matrice[MAX][MAX],int N,int M,int x,int y);
bool ControllaStato(int Matrice[MAX][MAX],int N,int M,int x,int y);
void RiempiMatrice(int Matrice[MAX][MAX],int N,int M);
void InizializzaMatrice(int Matrice[MAX][MAX],int N,int M);
#endif
