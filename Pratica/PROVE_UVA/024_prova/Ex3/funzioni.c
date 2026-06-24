#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funzioni.h"  // Include il file header

// Calcola la distanza tra due studenti usando il teorema di Pitagora
double CalcolaDistanzaEuclidea(int x1, int y1, int x2, int y2) {
    double dx = (double)x2 - x1;
    double dy = (double)y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

//trovo il minimo 
double min2(double a,double b){return (a<b)? a:b;}

// Inizializza la DP a un valore "infinito" (1e18)
void InzitDP(double DP[MAX_STATI]) {
    for (int i = 0; i < MAX_STATI; i++) DP[i] = 1e18; 
}

// Identifica il primo bit a 0 nella mask (il primo studente senza squadra)
int TrovaStudenteLibero(int mask, int n_totale) {
    for (int i = 0; i < n_totale; i++) {
        if (!(mask & (1 << i))) return i;
    }
    return -1;
}

double CalcolaDP(double DP[MAX_STATI], Coordinata Studenti[2 * N_MAX], int n_totale) {
        //1.Caso base: 0 studenti accoppiati = 0 distanza
        DP[0]=0;
        int limite_stati = (1 << n_totale);
        //2.Ricorreza:Per ogni stato mask
        for (int mask = 0; mask < limite_stati; mask++){
            // Se lo stato non è raggiungibile, lo saltiamo
            if (DP[mask] >= 1e17) continue;
            // 2.A:Prendiamo il primo studente disponibile
            int i=TrovaStudenteLibero(mask,n_totale);
            if(i==-1)continue;
            // 2.B:Proviamo ad accoppiare 'i' con ogni altro studente 'j' libero 
            for (int j = i+1; j < n_totale; j++){
                 // 2.C:Vediamo se lo studente j è libero
                 if (!(mask & (1 << j))){
                    //2.D:Definiamo lo stato futuro (mask originale + bit i e j accesi)
                    int nuova_mask = mask | (1 << i) | (1 << j);
                    //2.E:Calcoliamo la distanza tra i due studenti scelti
                    double d = CalcolaDistanzaEuclidea(Studenti[i].x1, Studenti[i].x2, Studenti[j].x1, Studenti[j].x2);
                    DP[nuova_mask] =min2(DP[nuova_mask],DP[mask]+d);
                 }    
            }  
        }
        //3.Ritorna il risultato 
        return DP[limite_stati - 1];      
}


