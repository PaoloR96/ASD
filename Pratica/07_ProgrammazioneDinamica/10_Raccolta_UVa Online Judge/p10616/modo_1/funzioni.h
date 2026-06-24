#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_T 10 //dimensioni casi di test

#define MAX_N 201
#define MAX_M 11
#define MAX_D 21
#define MAX_Q 11
/*STRUCT*/
typedef struct {
    /* data */
    int d;
    int m;
}Query;

typedef struct {
    /* data */
    int n;
    int q;
    int N[MAX_N];
   Query Q[MAX_Q];
}CasoTest;
/*Definizione varibile globale*/
extern long long DP[MAX_N][MAX_M][MAX_D];
/*METODI*/
void InitDP(long long DP[MAX_N][MAX_M][MAX_D],int n,int m,int d);
long long CalcolaDP(long long DP[MAX_N][MAX_M][MAX_D],int N[MAX_N] ,int n, int m, int d);

#endif