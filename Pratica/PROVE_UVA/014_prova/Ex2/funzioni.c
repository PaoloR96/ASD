#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header


void RiempiCasiTest(Sequenza *s, char stringaInput[]) {
    // 1. Memorizziamo la stringa originale per il confronto dopo
    strcpy(s->inputOriginale, stringaInput);
    s->dimensione = strlen(stringaInput);

    // 2. Copiamo i caratteri in V e li ordiniamo alfabeticamente
    // Il backtracking deve partire dal set ordinato per generare tutto in ordine.
    strcpy(s->V, stringaInput);
    qsort(s->V, s->dimensione, sizeof(char), compara);

    // 3. Inizializziamo l'array delle posizioni/usato a 0
    for (int i = 0; i < MAX; i++) s->usato[i] = 0;
    
}











// Funzione di supporto per ordinare i caratteri 
int compara(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
/*Varibili globali*/
int trovato = 0;   // Diventa 1 quando troviamo l'input originale
int concluso = 0;  // Diventa 1 quando abbiamo stampato il successore
char stringaTarget[MAX];
void TrovaSequenza(char insieme[], char attuale[], int usato[], int pos, int dim) {
        //1.Condizione di uscita
        if(concluso)return;// Se abbiamo già trovato e stampato, esci da tutto
        //2.Abbiamo costruito una stringa completa, devo vedere in quale stato mi trovo
        if (pos==dim){
                attuale[pos] = '\0'; // Chiudi la stringa
                if (trovato){
                    printf("%s\n", attuale); // Questo è il successore!
                    concluso = 1;
                    return;
                }
                if (strcmp(attuale, stringaTarget) == 0){
                    trovato=1;//ho trovato l'input il prossimo sarà il successore
                    return;
                }
        }
        //3.Ricorrenza, per ogni carattere
        for (int i = 0; i < dim; i++){
            if (!usato[i]){//se il carattere "i" non è stato usato
                // Salta i duplicati identici nella stessa posizione per efficienza
                if (i > 0 && insieme[i] == insieme[i-1] && !usato[i-1]) continue;
                usato[i]=1;//aggiorno il vettore dei caratteri usati
                attuale[pos]=insieme[i]; //inserisco l'elemento nell'insieme
                TrovaSequenza(insieme,attuale,usato,pos+1,dim);//passo al livello successivo
                usato[i] = 0; // BACKTRACK: libera la lettera per altri rami

            }
            
        }
        
}