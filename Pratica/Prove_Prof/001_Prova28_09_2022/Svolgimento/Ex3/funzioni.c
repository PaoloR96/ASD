#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header

double RicercaSoluzione(Parametri p){
    //1.Inizializzo l'intervallo low e high
    double low=0.0;
    double high=1.0;
    double answ=-1.0;
    
    //Ci fermiamo quando l'intervallo è piccolissimo
    // 0.0000001 è la "precisione" che garantisce le 4 cifre decimali richieste
    while ((high-low)>INTERVALLO){
        //1.Calcolo il punto medio
        double mid=(high+low)/2.0;
        //2.Calcolo la funzione in mid
        double risultato=CacolaFunzione(p,mid);
        //3.Verifico il segno della funzione
        if (risultato>0){
            answ=mid;// ho trovato un possibile candidato come soluzione
            low=mid;// posso spostarmi più a destra
        }else{
            answ=mid;// ho trovato un possibile candidato come soluzione
            high=mid;// posso spostarmi più a sinistra
        }
    }
    return answ;
}
/*p∗e−x	+q∗sin(x)+r∗cos(x)+s∗tan(x)+t∗x2+u=0*/
double CacolaFunzione(Parametri p,double x){
    return p.p*exp(-x)+p.q*sin(x)+p.r*cos(x)+p.s*tan(x)+p.t*x*x+p.u;
}