#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int CalcolaPosizione(int n,int Depth,int pos,int livello){
        //1.Caso base:Ho raggiunto la profondità Depth
        if (livello==Depth){
            return pos;
        }
        //2.Ricorrenza:Mi sposto all'interno dell'albero usando la logica dei flag (Pari/Dispari)
        //2A:Se n è DISPARI, la pallina è la 1a, 3a, 5a... che passa di qui.
        //Trova il flag a FALSO, lo mette a VERO e va a SINISTRA
        if (n%2!=0){
           int prossima_n=(n+1)/2; // Quante palline andranno a sinistra
           int prossima_pos = 2*pos ;   // Figlio sinistro
           //vado a sx dell'albero
           return CalcolaPosizione(prossima_n,Depth,prossima_pos,livello+1);
        }else{
            //2B:Se n è PARI, la pallina è la 2a, 4a, 6a... che passa di qui.
            int prossima_n=n/2; //Quante palline andranno a destra
            int prossima_pos = 2*pos+1 ; // Figlio destro
            //vado a dx dell'albero
            return CalcolaPosizione(prossima_n,Depth,prossima_pos,livello+1);
        }
}
