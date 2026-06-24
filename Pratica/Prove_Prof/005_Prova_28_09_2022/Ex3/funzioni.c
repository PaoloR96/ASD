#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header

double CalcolaFunzione(Parametri P,double x){
    float valore=P.p*exp(-x)+P.q*sin(x)+P.r*cos(x)+P.s*tan(x)+P.t*x*x+P.u;
    return valore;
}


double TrovaSoluzione(Parametri p){
    //Inizializzo le variabili,defininedo l'intervallo di osservazione della mia funzione
    double low=0.0;
    double high=1.0;
    double answ=-1.0;
    //1.Applico la logica binaria
    while ((high-low)>0.0000001){
        //Calcolo il punto medio in questo modo in maniera tale da evitare possibili overflow
        double mid=low+(high-low)/2.0;
        //Valuto la mia funzione nel punto mid
        double valX=CalcolaFunzione(p,mid);
        //Se la funzione ha segno positivo
        if (valX>0){
            answ=mid; //Ho trovato la soluzione ma potrei trovare di meglio , pertando mi sposto più a destra
            low=mid;
        }else{//Se la funzione ha segno negativo
            answ=mid;// ho trovato un possibile candidato come soluzione ma potrei trovare di meglio 
            high=mid;//mi devo spostare più a sinsitra dell'intervallo
        }
    }
    return answ;
}

