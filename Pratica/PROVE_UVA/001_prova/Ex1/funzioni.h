#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX 100
#define SENTINELLA -999999
typedef struct {
    int dati[MAX];
    int dim;
} Sequenza;

// legge una sequenza
Sequenza leggiSequenza();
//stampa sequenza
void stampaSequenza(Sequenza s);
int  Merge(int A[MAX],int p, int r);
int CrossProduction(int A[MAX],int p,int q,int r);
int max4(int a, int b, int c, int d);
int max3(int a, int b, int c);
#endif
