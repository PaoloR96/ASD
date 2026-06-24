#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*struttura dati*/
typedef struct{
    /* data */
    double p;
    double q;
    double r;
    double s;
    double t;
    double u;
}Parametri;
/*Metodi*/
double CalcolaFunzione(Parametri P,double x);
double TrovaSoluzione(Parametri p);
#endif
