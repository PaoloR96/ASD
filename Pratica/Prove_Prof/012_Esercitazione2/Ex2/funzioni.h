#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<stdbool.h>
#define MAX 100
/*Metodi*/
bool IsSafe(int Labirinto[MAX][MAX],int N,int M,int x,int y);
bool TrovaPercorso(int Labirinto[MAX][MAX],int Percorso[MAX][MAX],int N,int M,int x,int y);
void InitMatrice(int Labirinto[MAX][MAX],int Percorso[MAX][MAX],int N,int M);
void StampaPercorso(int Percorso[MAX][MAX],int N,int M);
void  RiempiMatice(int Labirinto[MAX][MAX],int N,int M);
#endif
