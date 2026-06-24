#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>

#define MAX 100
#define DIM 6
#define DIM_MAX 501

typedef struct {
    int monete[6];
    int target;
} CasoTest;

int RiempiCasoTest(int Monete[DIM]);
void InitDp(int DP[DIM_MAX]);
int min(int a, int b);
void CalcolaDpUtente(int Monete[DIM], int tagli[], int DP[DIM_MAX]);
void CalcolaDpNegoziante(int tagli[], int DP[DIM_MAX]);
void minTotale(int DpNegoziante[DIM_MAX], int DpUtente[DIM_MAX], int target);

#endif