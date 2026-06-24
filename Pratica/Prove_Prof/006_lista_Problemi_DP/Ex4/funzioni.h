#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
typedef struct{
    /* data */
    int massimo;
    int minimo;
}Risultato;
/*VAR GLOBALI*/
extern int DPMax[MAX][MAX];
extern int DPMin[MAX][MAX];
/*Metodi*/
Risultato CalcolaDP(int DPMax[MAX][MAX],int DPMin[MAX][MAX], char operatori[MAX], int dim);
void InitDP(int DPMax[MAX][MAX],int DPMin[MAX][MAX],int numeri[MAX],int dim);

#endif
