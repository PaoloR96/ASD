#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct {
    /* data */
    int budget;
    int numeroClassi;
    int numProdotti[MAX];
    int Prodotti[MAX][MAX];
}CasoTest;
/*VAR GLOBALE*/
extern int DP[MAX][MAX];
/*METODI*/
void InitDP(int DP[MAX][MAX],int numeroClassi,int budget);
int CalcolaDP(int DP[MAX][MAX],CasoTest T);
int max2(int a,int b);
void RiempiClasse(CasoTest *T, int index);
#endif
