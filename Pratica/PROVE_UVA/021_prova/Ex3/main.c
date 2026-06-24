#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c 

int main() {
    int NTest=0, index=0;
    CasoTest Test[MAX_C];
    printf("SAMPLE INPUT: \n");
    
    /*Definisco l'input:*/
    //1.Definisco il numero di casi di test
    if (scanf("%d", &NTest) != 1) return 0;
    printf("\n");
    
    while (index < NTest) {
        //2.Definisco la lunghezza del tragetto
        scanf("%d", &Test[index].lunTraghetto);
        
        //3.Inserisco le auto
        int numeroAuto = InserisciDati(Test[index].Auto);
        Test[index].numeroAuto = numeroAuto;
        
        //4.passo al caso di test successivo
        index++;
    }
    
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++) {
         //1.Inizializzo la DP[numAuto+1][lunghezzaTraghetto+1]
         int L_cm = Test[i].lunTraghetto * 100; // Conversione metri in cm
         InitDP(DP, Test[i].numeroAuto, Test[i].lunTraghetto);
         
         //2.Riempio la tabella DP e stampo
         CalcolaDP(DP, Test[i].Auto, Test[i].numeroAuto, L_cm);
         
         if (i < index - 1) printf("\n"); // Riga vuota tra i casi
    }
    
    printf("\n");
    system("pause");
    return 0;
}