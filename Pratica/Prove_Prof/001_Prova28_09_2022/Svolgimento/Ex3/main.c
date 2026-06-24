#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    double Risultato[100];
    int index=0;
    char linea[2100];
    while (index<100 && fgets(linea,sizeof(linea),stdin)){
        //1. Rimuovi il carattere 'newline' alla fine della stringa
        linea[strcspn(linea,"\n\r")]=0;
        //2.Verifico se nella stringa c'è END
        if(strcmp(linea,"END")==0)break;
        //3.Se la riga è vuota, passa alla prossima
        if (linea[0] == '\0') continue;
        //4.Ora devo converto la stringa
         Parametri p;
         int i=0;
         char *token=strtok(linea," ");
         while (token!=NULL && i<6){
            if(i==0)p.p=atoi(token);
            if(i==1)p.q=atoi(token);
            if(i==2)p.r=atoi(token);
            if(i==3)p.s=atoi(token);
            if(i==4)p.t=atoi(token);
            if(i==5)p.u=atoi(token);
            i++;
            token = strtok(NULL, " ");
         }
        //5.Verifico se esiste soluzione
        double fLow = CacolaFunzione(p, 0.0);
        double fHigh = CacolaFunzione(p, 1.0);
        if (fLow * fHigh > 0) {
            Risultato[index]=INT_MAX;
        } else {
            //6.Calcolo soluzione
            Risultato[index] = RicercaSoluzione(p);
        }         
         //passo al caso di test successivo
         index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) {
        if (Risultato[i]==INT_MAX){
            printf("No Solution!\n");
        }else{
            printf("%.4f\n", Risultato[i]);
        }    
    }
    system("pause");
    return 0;
}

/*
Complessità:O(N log(1/ε)) con ε precisione richiesta dal problema (soglia di arresto) 

*/