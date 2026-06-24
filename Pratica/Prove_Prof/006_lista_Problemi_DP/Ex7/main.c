#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Risultato[MAX];
    int index=0;
    char Stringa1[MAX],Stringa2[MAX];
    
    while (1){
        // 1. Inserisco le due stringhe
        if (fgets(Stringa1, MAX, stdin) == NULL) break; 
        if(Stringa1[0]=='&') break; 
        if (fgets(Stringa2, MAX, stdin) == NULL) break;
        // 2. Pulisco le due stringhe
        Stringa1[strcspn(Stringa1,"\r\n")]='\0';
        Stringa2[strcspn(Stringa2, "\r\n")] = '\0';
        // 3. Calcolo le dim delle due stringhe
        int n=strlen(Stringa1);
        int m=strlen(Stringa2);
        // 4. Applico la logica DP
        InitDP(DP,n,m);
        Risultato[index]=CalcolaDP(DP,Stringa1,n,Stringa2,m);
        
        // 5. Passo al prossimo caso di test
        index++;
    }
    
    printf("SAMPLE OUTPUT:\n");
    int caso=1;
    for (int i = 0; i < index; i++){
        // CORREZIONE 4: Mancavano i due punti ":" dopo il numero del caso per rispettare l'output richiesto
        printf("Caso #%d: numero massimo = %d\n", caso, Risultato[i]); 
        caso++; // CORREZIONE 5: Bisogna incrementare la variabile 'caso' a ogni ciclo
    }
    
    system("pause");
    return 0;
}

/*
Complessità: O(|n||*m|)
Ricorrenza: Se carattereX==Stringa2[j-1])    allora    DP[i][j]=1+DP[i-1][j-1];
            Se sono diversi                  allora    DP[i][j]=max2(DP[i-1][j],DP[i][j-1]);
                               
*/