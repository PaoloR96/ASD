#ifndef FUNZIONI_H
#define FUNZIONI_H
#define  MAX 100
typedef struct{
    /* data */
    int X;
    int Y;
}Posizione;
/*var globali*/
extern int DP[MAX];
/*Metodi*/
int ComporaValori(const void *a,const void *b);
int InitDP(int DP[MAX],int dim);
int CalcolaDP(int DP[MAX],int Y[MAX],int dim);
int max2(int a,int b);
#endif
