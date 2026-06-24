#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100

typedef struct {
    int Vettore[MAX];
    int F[MAX];
}NumeroFlip;

/*Metodi*/
int TrovaPosizioneMAX(int V[],int dim);
void Swap(int *a, int *b);
NumeroFlip CalcolaNumeroFlip(int V[MAX],int dim);
#endif
