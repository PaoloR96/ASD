#ifndef FUNZIONI_H
#define FUNZIONI_H
#define DIM_TEST 65
#define MAX 100


typedef struct{
    /* data */
    int dimQ;
    int Q[MAX];
}Query;

typedef struct{
    /* data */
    int dimB;
    int B[MAX];
}Biglie;

/*Metodi*/
void RiempiElementi(int Vett[MAX],int dim);
int ComparaElementi(const void* a,const void * b);
void TrovaElmento(int Biglie[MAX],int dimB,int Query[MAX],int dimQ);
int RicercaBinaria(int Biglie[MAX],int dimB,int target);
#endif
