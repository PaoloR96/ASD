#ifndef FUNZIONI_H
#define FUNZIONI_H

#define N_MAX 10000
//definisco la struttura Punto
typedef struct funzioni{
    /* data */
    double x;
    double y;
}Punto;
//Metodi
double min(double a, double b);
double distanzaSq(Punto p1, Punto p2);
double DistanzaBruta(Punto P[], int start, int end);
float IspezionaPunti(Punto Coordinata[N_MAX],int start,int q,int end);
double CalcolaSequenza(Punto Coordinata[], int start, int end);
int comparaY(const void* a, const void* b);
int comparaX(const void* a, const void* b);
double IspezionaStriscia(Punto Coordinata[], int start, int end, double midX, double delta);





#endif
