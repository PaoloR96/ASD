#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    double Vett[MAX];
    Parametri p;
    double Ris[MAX];
    char Sequenza[MAX];
    int indice=0;
    while (1){
        //Fase A:Manipolazione Stringa
        //1)Inserimento stringa
        if(fgets(Sequenza,sizeof(Sequenza),stdin)==NULL)break;
        //2)Rimuovo eventuali spazi
        Sequenza[strcspn(Sequenza,"\n\r")]='\0';
        //3)Nel caso trovo END esco
        if(strcmp(Sequenza,"END")==0)break;
        //4)Converto la stringa in double
        int index=0;
        char *ptr=Sequenza;
        char *fine;
        while (*ptr!='\0'){
            double temp = strtod(ptr, &fine);
            //Se non trovo nessun numero esco
            if(ptr==fine)break;
            Vett[index]=temp;
            index++;
            ptr=fine;
        }
        //5)Copio i dati dentro Parametri P
        for (int i = 0; i < index; i++){
            if(i==0)p.p= Vett[i];
            if(i==1)p.q= Vett[i];
            if(i==2)p.r= Vett[i];
            if(i==3)p.s= Vett[i];
            if(i==4)p.t= Vett[i];
            if(i==5)p.u= Vett[i];
        }
        
       //6) Calcolo della funzione
    /*  Determino il segno della funzione utilizzando il Teorema degli zeri
        Se i due valori hanno lo stesso segno (concordi), la funzione non attraversa lo zero nell’intervallo
        Se invece hanno segno opposto (discordi), allora esiste almeno una soluzione (la funzione interseca lo zero)
    */    
    double fLow = CalcolaFunzione(p, 0.0);
        double fHigh = CalcolaFunzione(p, 1.0);
        if (fLow * fHigh > 0) {
            Ris[indice]=INT_MAX;
        } else {
            //6.Calcolo soluzione
            Ris[indice]=TrovaSoluzione(p);
        } 
       
        //7)passo al prossimo caso di test
        indice++;
    }
    
 printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < indice; i++) {
        if (Ris[i]==INT_MAX){
            printf("No Solution!\n");
        }else{
            printf("%.4f\n", Ris[i]);
        }    
    }
    system("pause");
    return 0;
}

/*
Complessità:O(N log(1/ε)) con ε precisione richiesta dal problema (soglia di arresto) 

*/