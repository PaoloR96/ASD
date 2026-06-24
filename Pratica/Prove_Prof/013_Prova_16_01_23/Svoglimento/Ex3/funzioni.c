#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

const char* TrovaPrefissoComune(const char *words[],int size){
    static char risultato[100];
    int i=0;
    while (1){
        // 1. Prendo il carattere della prima parola
        char c=words[0][i];
         //2.Se arrivo alla fine della prima parola, il prefisso è completo
        if(c=='\0'){
            risultato[i]='\0';// chiudo la stringa
            return risultato;
        }
        //3.Confronto lo stesso carattere i-esimo con il carattere j-esimo delle altre parole
        for (int j = 1; j < size; j++){
            if (words[j][i]!=c || words[j][i]=='\0'){ // Se il carattere è diverso oppure la parola è finita
                risultato[i]='\0';// chiudo il risultato
                return risultato;// ritorno il prefisso trovato fino a qui
            }
        }
        // 4. Se tutti i caratteri sono uguali, lo salvo nel risultato
        risultato[i]=c;
        i++;//passo al prossimo carattere
    }

}