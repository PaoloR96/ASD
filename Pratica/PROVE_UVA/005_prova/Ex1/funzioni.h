#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_SAMPLES 10  // perché S ≤ 2C e C ≤ 5 → max 10

typedef struct {
    int C;                 // numero di camere
    int S;                 // numero di campioni
    int masses[MAX_SAMPLES]; // array delle masse
} Dati;
/*metodi*/
int compare(const void *a,const void *b);
Dati AggiungiZero(Dati dataset,int numeroZero);
double Somma(Dati dataset);
double CalcolaSbilanciamento(Dati dataset, double AM);

#endif
