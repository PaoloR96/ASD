#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header
void trova_destinazione(char attuale[], int ora, Percorso *p, char risultato[]){
        //1_Caso base: Rilevato ciclo infinito
        if (gia_visitato(attuale,p)){
            strcpy(risultato,"9999");
            return;
        }
        //Aggiungo l'estensione al percorso
        strcpy(p->lista[p->contatore],attuale);
        p->contatore++;
        //2_Ricorrenza:Cerco se esiste una regola attiva
        char *prossimo_target = cerca_regola_attiva(attuale, ora);
        if (prossimo_target != NULL) {
        // 3. Passo ricorsivo: Segui l'inoltro, applico il backtracking
        trova_destinazione(prossimo_target, ora, p, risultato);
    } else {
        // 4. Caso base: Nessun inoltro, il telefono squilla qui
        strcpy(risultato, attuale);
    }

}


// Funzione per verificare se l'estensione è già stata visitata
bool gia_visitato(char estensione[], Percorso *p){
    for (int i = 0; i < p->contatore; i++){
        if(strcmp(p->lista[i],estensione)==0)return true;
    }
    return false;
}


 Regola archivio[100]; 
 int num_regole;
 char* cerca_regola_attiva(char attuale[], int ora) {
    for (int i = 0; i < num_regole; i++) {
        // Verifica estensione sorgente 
        if (strcmp(archivio[i].sorgente, attuale) == 0) {
            // Verifica se l'ora della chiamata è nell'intervallo 
            if (ora >= archivio[i].inizio && ora <= (archivio[i].inizio + archivio[i].durata)) {
                return archivio[i].destinazione;
            }
        }
    }
    return NULL; // Nessun inoltro attivo 
}