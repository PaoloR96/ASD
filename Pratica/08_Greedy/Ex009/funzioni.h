#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 10000
typedef struct{
        int n; //numero di teste del drago
        int m; //numero di cavalieri nel regno
        int N[MAX]; //diametro delle teste del drago in cm
        int M[MAX]; //altezza dei cavalieri di Loowater, anch'essa in cm
}CasoTest;
/*Metodi*/
void StampaCasiTest(int A[],int dim);
int Compara(const void *a,const void *b);
void CalcolaSequenza(CasoTest C);




#endif
