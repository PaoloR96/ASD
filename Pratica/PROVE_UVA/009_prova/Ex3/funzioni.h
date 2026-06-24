#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100

typedef struct {
    int N1;
    int N2;
    int torre1[MAX];
    int torre2[MAX];
    int risultato;
} CasoDiTest;
/*MATRICE DP*/
extern int DP[MAX][MAX];
/*PROTOTIPI*/
void StampaCasiTest(int V[MAX],int dim);
void InizializzaDP(int DP[MAX][MAX],int dim1,int dim2);
int max(int a, int b);
void CalcolaDP(int DP[MAX][MAX],int T1[MAX],int dim1,int T2[MAX],int dim2);

#endif
