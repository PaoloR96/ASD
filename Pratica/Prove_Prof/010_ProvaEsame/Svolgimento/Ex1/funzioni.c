#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void CalcolaSequenza(char Insieme[MAX],int index,int N,int flag){
        //Condizione di uscita:Ho creato una sequenza
        if(index==N){
            //Chiudo la sequnza
            Insieme[index]='\0';
            //Converto la stringa di bit in decimale
            ConvertiBinarioToDecimale(Insieme);
            return;
        }
        // Ricorsione: Creo la sequenza con la logica del Codice di Gray
        // Se flag == 0, esploro prima lo '0' e poi l''1'
    if (flag == 0) {
        Insieme[index] = '0'; 
        CalcolaSequenza(Insieme, index + 1, N, 0); // In questo ramo continuo con 0
        
        Insieme[index] = '1'; 
        CalcolaSequenza(Insieme, index + 1, N, 1); // In questo ramo passo ad  1
    } 
    // Se flag == 1, esploro prima l''1' e poi lo '0'
    else {
        Insieme[index] = '1';
        CalcolaSequenza(Insieme, index + 1, N, 0);// In questo ramo continuo con 0
        
        Insieme[index] = '0';
        CalcolaSequenza(Insieme, index + 1, N, 1); // In questo ramo passo ad  1
    }

}


void  ConvertiBinarioToDecimale(char Insieme[MAX]){
    int decimale = 0;
    for(int i = 0; Insieme[i] != '\0'; i++) {
        decimale = decimale * 2 + (Insieme[i] - '0');
    }
    printf("%d\n", decimale);
}