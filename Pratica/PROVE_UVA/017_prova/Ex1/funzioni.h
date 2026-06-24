#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAXl 100 //max libri disponibili
#define MAXc 1000000 //costo max ogni libro

typedef struct {
    /* data */
    int numLibri;
    int N[MAXl];
    int M;
}Test;

void RiempiCasoTest(Test *T, int dim);
int ComparaN(const void *a, const void *b);
void CercaDifferenzaMin(int P[MAXl],int dim,int M);
int RicercaBinariaTarget(int P[MAXl],int Target,int low,int hight);

#endif
