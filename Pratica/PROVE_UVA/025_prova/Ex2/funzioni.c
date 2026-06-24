#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*VARIABILI GLOBALI*/
int minimoGlob=INT_MAX;
int usato[MAX_NODI];
char soluzioneOttima[MAX_NODI + 1]; // Stringa per memorizzare il risultato

void CalcolaSequenza(char attuale[MAX_NODI], int pos, Grafo G,int maxDistanzaCorrente){ 
        //1.Condizione di uscita:ho creato la sequenza
        if (pos==G.numNodi){
            // Salva attuale in SoluzioneOttima
            if (maxDistanzaCorrente < minimoGlob) {
                minimoGlob = maxDistanzaCorrente;
                for (int i = 0; i < G.numNodi; i++)soluzioneOttima[i]=attuale[i];
                soluzioneOttima[G.numNodi]='\0';
            }
        return;
        }
        //2.Ricorsione:Provo a creare la sequenza
        for (int i = 0; i < MAX_NODI; i++){
            if (!usato[i]) {
                    int d = CalcolaDistanzaNodo(i, pos, G, attuale);
                    int nuovaMaxDistanza = (d > maxDistanzaCorrente) ? d : maxDistanzaCorrente;
                    // 2_1.Pruning: procedi solo se la bandwidth attuale è migliore del record
                    if (nuovaMaxDistanza < minimoGlob) {
                        usato[i] = 1;
                        attuale[pos]=G.Nodo[i];
                        CalcolaSequenza(attuale,pos+1, G,nuovaMaxDistanza);
                        usato[i] = 0;//backtracking, se la ricorsione termina torno indietro e passo a nodo successivo
                    }
                    //provo un altro nodo
            }
        }
}




int CalcolaDistanzaNodo(int indiceNuovoNodo, int posAttuale, Grafo G, char attuale[]) {
    int maxDistNodo = 0;
    // Scorri i nodi già inseriti nella sequenza (da 0 a posAttuale - 1)
    for (int i = 0; i < posAttuale; i++) {
        // Cerca se attuale[i] è collegato al nodo G.Nodo[indiceNuovoNodo]
        if (SonoConnessi(G, G.Nodo[indiceNuovoNodo], attuale[i])) {
            int dist = posAttuale - i;
            if (dist > maxDistNodo) maxDistNodo = dist;
        }
    }
    return maxDistNodo;
}


int SonoConnessi(Grafo G, char nodoX, char nodoAtt) {
    int indiceX = -1;
    int indiceAtt = -1;
    // 1. Trova gli indici numerici dei due nodi nel grafo
    for (int i = 0; i < G.numNodi; i++) {
        if (G.Nodo[i] == nodoX) indiceX = i;
        if (G.Nodo[i] == nodoAtt) indiceAtt = i;
        // Se abbiamo trovato entrambi gli indici, possiamo fermare il ciclo
        if (indiceX != -1 && indiceAtt != -1) break;
        
    }
    // 2. Se uno dei nodi non esiste nel grafo  ritorna 0
    if (indiceX == -1 || indiceAtt == -1) return 0;
    
    // 3. Verifica nella matrice di adiacenza se esiste un arco (1) tra i due
    if (G.Matrice[indiceX][indiceAtt] == 1) return 1; // Connessi
    return 0; // Non connessi
}