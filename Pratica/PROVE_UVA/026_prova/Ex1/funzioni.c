#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header
/*
    Calcola:
    p * e^(-x) + q * sin(x) + r * cos(x) +
    s * tan(x) + t * x^2 + u
*/
double CalcolaFunzione(Parametri p, double x){
    return (p.p * exp(-x)) +(p.q * sin(x)) +
           (p.r * cos(x)) +(p.s * tan(x)) +
           (p.t * pow(x, 2)) +p.u;
}

double CalcolaSoluzione(Parametri p, double low,double high){
    //1.Calcolo mid
    double mid=(low+high)/2.0;;
    //2.Condizione di uscita
    if(high - low < 0.0000001)return mid;
    //3.Calcolo F(mid)
    //Se la funzione calcolata in mid è positiva mi sposto a destra del mio intervallo
    if(CalcolaFunzione(p,mid)>0)
        return CalcolaSoluzione(p,mid,high);
    else
    //Mi sposto a sinistra
        return CalcolaSoluzione(p,low,mid);
}