#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 128
extern int DP[MAX][MAX];
void CalcolaDP(int DP[MAX][MAX], char Seq[], int N);
void InitDP(int DP[MAX][MAX], int N);
#endif
