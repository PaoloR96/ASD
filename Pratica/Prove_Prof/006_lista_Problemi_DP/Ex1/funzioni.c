#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*
n=capienza traghetto
t=tempo tragitto
m=numero di auto al terminal
Tempi[]=tempi arrivi auto
*/

Risultato CalcolaViaggio(int n,int t,int m, int Tempi[MAX]){
    /*definizione delle variabili*/
    Risultato r={0,0};
    int TempoAssoluto=0;
    int numeroViaggi=0;
    int i=0;
    //determino il primo carico:In modo tale da poter bilanciare le auto da poter caricare tra gli n viaggi
    int PrimoCarico=m%n;
    //Se il rapporto è 0 devo caricare n auto
    if(PrimoCarico==0)PrimoCarico=n;
    while (i<m){//Per ogni auto i in attesa di essere caricata
        int numeroAutoCaricate=0;
        int TempoCorrente=0;
        //LOGICA GREEDY:
        /*Il traghetto parte se:
        1)Sono state caricate n auto in modo tale da non sfofare la capienza n del traghetto
        2)Ho caricato tutte le auto rimanenti
        */
       //Vedo se effettuare il primo carico o i restanti
       int limiteAuto=(i==0)?PrimoCarico:n;
        while (numeroAutoCaricate<limiteAuto && i<m){
            if (TempoCorrente<Tempi[i])TempoCorrente=Tempi[i];
            i++;//riempio il traghetto 
            numeroAutoCaricate++;//carico l'autp
        }
        //Arrivato a questo punto posso partire per il iesimo viaggio
        //Punto1:Aggiorno il TempoAssoluto
        if(TempoAssoluto<TempoCorrente)TempoAssoluto=TempoCorrente;
        //Aggiungo al TempoAssoluto il viaggio di andata t
        TempoAssoluto+=t;
        //Se ci sono altre auto da prendere aggiungo anche il tempo per il viaggio di ritorno per caricare le restanti auto
        if(i<m)TempoAssoluto+=t;
        //Incremento il numero di viaggi
        numeroViaggi++;
        
    }
    r.numeroViaggi=numeroViaggi;
    r.TempoStimato=TempoAssoluto;
    return r;
}
