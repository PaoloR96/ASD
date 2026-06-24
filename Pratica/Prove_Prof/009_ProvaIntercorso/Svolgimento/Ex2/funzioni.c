#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
//Vedo se un numero è primo
bool IsPrimo(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
void CalcolaSequenza(int Insieme[MAX], int S, int N, int P, int index, int sommaParziale){
        //1.Condizione di uscita:Ho creato una sequenza
        if (sommaParziale==S){//Ho raggiunto la Somma S
            if (index==N){//Ho riempito la sequenza di dimensione N
                StampaSequenza(Insieme,index);
            }
            return;
        }
        //2.Condizione di potatura:Effettuo il pruning dello spazio di soluzioni che non rispettono 
        // Se sforo la somma desiderata o ho già inserito N elementi senza raggiungere S, mi fermo.
        if(sommaParziale>S ||index==N)return;
        
        //3.Ricorsione:Creo la sequenza
        for (int numero = P+1; numero <= S; numero++){
            if (IsPrimo(numero)){
                Insieme[index] = numero; // Inserisco il numero primo
                CalcolaSequenza(Insieme,S, N,numero, index+1,sommaParziale+numero);//Passo al livello successivo
                // Il backtracking avverrà in modo automatico: se una volta chiamata la ricorsione 
                // mi imbatto con la condizione al punto 2, attraverso il pruning vado a tagliare 
                // quella soluzione e al prossimo ciclo sovrascrivo Insieme[index].
            }
            
        }
}

void StampaSequenza(int Insieme[MAX],int dim){
    for (int i = 0; i < dim; i++)printf("%d ",Insieme[i]);
    printf("\n");
}
