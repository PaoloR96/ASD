#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*
n=capienza traghetto
t= tempo per percorrere la tratta
m=numero di auto presenti
*/
Risultato CaricaTraghetto(int n,int t, int m, int Tempi[]) {
    /*Variabili*/
    Risultato r={0,0};
    int TempoAssoluto=0;//Salveremo ad ogni iterazione il tempo minimo assoluto
    int NumeroViaggi=0;//numero di viaggi che il traghetto effettuerà
    int i=0;
    // DETERMINO QUANTE AUTO CARICARE NEL PRIMO VIAGGIO
    int primoCarico = m % n;
    if (primoCarico == 0) primoCarico = n;

    while (i<m){//Fino a quando ci sono auto da caricare
        int TempoCorrente=0;
        int autoCaricate=0;
        // Nel primo ciclo usa 'primoCarico', nei successivi usa 'n'
        int limiteAttuale = (i == 0) ? primoCarico : n;
        
        //Logica Greedy
        /*    
            Le condizioni affinchè il traghetto parte sono due:
            1)Ho caricato n auto
            2)Non ci sono più auto
        */
        while (autoCaricate<limiteAttuale && i<m){
            //Aggiorno il tempo di partenza man mano che carico le auto
            if(Tempi[i]>TempoCorrente)TempoCorrente=Tempi[i];
            autoCaricate++;
            i++;
        }
        //Ad ogni iterazione aggiono:
        if (TempoCorrente>TempoAssoluto)TempoAssoluto=TempoCorrente;
        //Al tempo di partenza aggiungo t che rappresenta il tempo di percorrenza: definisco il viaggio d'andata
        TempoAssoluto+=t;
        //Incremneto il numero di viaggi
        NumeroViaggi++;
        // Se ci sono ancora auto da prendere, il traghetto deve tornare indietro
        if(i<m)TempoAssoluto+=t;
    }
    //salvo i dati
    r.numeroViaggi=NumeroViaggi;
    r.TempoMin=TempoAssoluto;
    return r;
}