#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 8
void StampaVettore(int vettore[MAX],int n);
void InizializzaDP(int DP[MAX],int DPIndici[MAX],int n);
int CalcolaDP(int vettore[MAX],int DP[MAX],int DPIndici[MAX],int n);
void StampaSottosequenza(int vettore[MAX], int DPIndici[MAX], int i);

#endif
