#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int A[10]={1,1,1,1,2,3,4,5,5,6};
    StampaArray(A,10);
    contaOccorrenzeUno(A,10);
 


    system("pause");
    return 0;
}
/*Poiché il vettore è ordinato, tutte le occorrenze di 1 sono contigue.
Per contarle basta trovare il primo e l’ultimo indice in cui compare 1.
Entrambe le ricerche si possono fare con una ricerca binaria ricorsiva, che ha complessità O(log n).
Se trovo un 1 a metà vettore, non posso fermarmi: potrebbe esserci un 1 più a sinistra (o più a destra), quindi continuo la ricerca nella metà opportuna.
Alla fine ottengo i due indici e il numero di occorrenze è la differenza più uno.


Ogni chiamata ricorsiva dimezza il problema:

prima cerchi in [0..n/2]

poi in [0..n/4]

poi in [0..n/8]

…

dopo circa log₂(n) passi arrivi a intervallo vuoto

*/