#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct {
    /* data */
    double p;
    double q;
    double r;
    double s;
    double t;
    double u;
}Parametri;

/*Metodi*/
double CalcolaFunzione(Parametri p,double x);
double CalcolaSoluzione(Parametri p, double low,double high);




#endif
