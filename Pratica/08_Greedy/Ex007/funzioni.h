#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_N 10000
//Struttura dati
typedef struct {
    int posizione;
    int raggio;
    double intervallo_sx;
    double intervallo_dx;
} Irrigatore;

typedef struct {
    int n;
    int l;
    int w;
    Irrigatore irr[MAX_N];
} Caso;
//Metodi
void stampaCaso(Caso c);
void calcolaIntervalli(Irrigatore irr[], int n, int w);
int ComparaValori(const void *a, const void *b);
int RisolviSequenza(Irrigatore irr[], int n, double L);
#endif
