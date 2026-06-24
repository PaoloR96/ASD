#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "funzioni.h"  // Include il file header
//Stampo elementi
void stampaCaso(Caso c) {
    printf("%d %d %d\n", c.n, c.l, c.w);

    for (int i = 0; i < c.n; i++) {
        printf("%d %d\n",
               c.irr[i].posizione,
               c.irr[i].raggio);
    }
}



//Calcolo gli intervalli (pos-dx,pos+dx) per ogni irrigatori
void calcolaIntervalli(Irrigatore irr[], int n, int w) {
    for (int i = 0; i < n; i++) {
        double metà_w = w / 2.0;
        if (irr[i].raggio <= metà_w) {
            // irrigatore inutile (non copre tutta la larghezza)
            irr[i].intervallo_sx = -1;
            irr[i].intervallo_dx = -1;
        } else {
            double dx = sqrt(irr[i].raggio * irr[i].raggio - metà_w * metà_w);
            //Calcolo e salvo i valori [pos-dx,pos+dx] 
            irr[i].intervallo_sx = irr[i].posizione - dx;
            irr[i].intervallo_dx = irr[i].posizione + dx;
        }
    }
}

//Ordino gli elementi in senso crescente per  pos-dx
int ComparaValori(const void *a, const void *b) {
    Irrigatore *irr1 = (Irrigatore *)a;
    Irrigatore *irr2 = (Irrigatore *)b;

    if (irr1->intervallo_sx < irr2->intervallo_sx) return -1;
    if (irr1->intervallo_sx > irr2->intervallo_sx) return 1;

    // a parità di sx, ordina per dx decrescente
    if (irr1->intervallo_dx > irr2->intervallo_dx) return -1;
    if (irr1->intervallo_dx < irr2->intervallo_dx) return 1;

    return 0;
}
//Logica Greedy
int RisolviSequenza(Irrigatore irr[], int n, double L){
        //variabili
        double coperto_fino_a=0;
        int IrrigatoriUsati=0;
        int i=0;
        while (coperto_fino_a<L){
            double best = coperto_fino_a;
            bool trovato = false;
            //logica greedy:Controlla tutti gli irrigatori che iniziano entro la zona già coperta
            while (i<n && irr[i].intervallo_sx<=coperto_fino_a){
                if(irr[i].intervallo_dx>best){
                    best=irr[i].intervallo_dx; // Miglior estremo che possiamo raggiungere in questo passo
                    trovato=true;
                }
                i++;    
            }
            // Se non abbiamo trovato nessun irrigatore che estenda la copertura
            if(!trovato)return -1;
            // Aggiorna estremo coperto e incrementa irrigatori usate
            coperto_fino_a=best;
            IrrigatoriUsati++;
        }
        return IrrigatoriUsati;
}