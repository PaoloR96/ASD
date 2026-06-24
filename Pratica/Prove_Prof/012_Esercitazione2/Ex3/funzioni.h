#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
#include<stdbool.h>
bool IsSafe(int Matrice[MAX][MAX],int x,int y,int N,int M);
void TrovaPercorsi(int Matrice[MAX][MAX],int Percorso[MAX],int x,int y,int N,int M,int index);
void RiempiMatrice(int Matrice[MAX][MAX],int N,int M);
void InizializzaMatrice(int Matrice[MAX][MAX],int Percorso[MAX],int N,int M);
void StampaPercorso(int Percorso[MAX],int dim);
#endif
