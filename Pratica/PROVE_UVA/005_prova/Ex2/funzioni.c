#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

 int CalcolaModi(BarCode bc, int unitàRimanenti, int barreRimanenti){
    //condizione di uscita
    if (barreRimanenti==0){// Se abbiamo esaurito le barre da piazzare
        if(unitàRimanenti==0)return 1;//Se abbiamo usato esattamente n unità, abbiamo trovato 1 combinazione valida
        return 0;
    }
    //ricorsione
    int contatoreParziale=0;
    for (int i = 1; i <= bc.m; i++){//valutiamo la larghezza 
        // Prova a sottrarre la larghezza 'i' dalle unità rimanenti e passa alla prossima barra (barreRimanenti - 1)
         contatoreParziale+=CalcolaModi(bc,unitàRimanenti-i, barreRimanenti-1);
    }
    return contatoreParziale;
    
}