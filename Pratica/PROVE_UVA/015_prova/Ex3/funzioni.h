#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 20
typedef struct {
    /* data */
    int Sequenza[MAX];
    int posizione[MAX];
} CasoTest;

/*Metodi*/
int ComparaElementi(const void *a, const void *b);
void OrdinaCaso(CasoTest *ct, int n);
void InizializzaDP(int DP[MAX+1][MAX+1],int dim);
int CalcolaSequenzaDP(int DP[MAX+1][MAX+1],int sequenzaCorretta[MAX],int SequenzaStudente[MAX] ,int dim);
int max2(int a, int b);

#endif
