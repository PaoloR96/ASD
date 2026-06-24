#ifndef FUNZIONI_H
#define FUNZIONI_H
#define INTERVALLO 0.0000001
/*p, q, r, s, t ed u */
typedef struct{
    /* data */
    double p,q,r,s,t,u;
}Parametri;
/*Metodi*/
double CacolaFunzione(Parametri p,double x);
double RicercaSoluzione(Parametri p);
#endif
