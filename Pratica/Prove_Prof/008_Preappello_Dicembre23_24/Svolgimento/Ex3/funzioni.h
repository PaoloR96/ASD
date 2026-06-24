#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct{
    /* data */
    int budget;
    int Numclassi;
    int NumProdotti[MAX];
    int Prodotti[MAX][MAX];
}CasoTest;
/*VAR GLOBALI*/
extern int DP[MAX][MAX];
/*Metodi*/
void InserisciProdotti(int Prodotti[MAX],int dim);
void InitDP(int DP[MAX][MAX],int numeroClassi,int budget);
int CalcolaDP(int DP[MAX][MAX], CasoTest ct);
int max2(int a,int b);
#endif
