#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 5607
typedef struct {
    /* data */
    int Peso;
    int Forza;
}Tartaruga;
/*Metodi*/
int ComparaForza(const void * a,const void * b);
void initDP(int DP[MAX],int dim);
int CalcolaDP(int DP[MAX],Tartaruga T[MAX],int dim);
int min2(int a, int b);
#endif
