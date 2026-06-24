#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Risultato[MAX_SIZE],index=0;
    char linea[2048];
    while (index<MAX_SIZE && fgets(linea,sizeof(linea),stdin)){
        //Se ho inserito END esco dal ciclo
        //Rimuovi il carattere 'newline' alla fine della stringa
        linea[strcspn(linea, "\r\n")] = 0;
        if(strcmp(linea,"END")==0)break;
        //Passo i dati dalla stringa linea ad un vettore di interi
        int arr[MAX_SIZE];
        int n = 0;
        char *token=strtok(linea, " ");
        while (token!=NULL){
            arr[n++]=atoi(token);
            token=strtok(NULL, " ");
        }
        //inizializzo DP
        for(int i=0;i<n;i++)DP[i]=0;
        //Calcolo DP
        Risultato[index]=CalcolaDP(arr,DP,n);
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for(int i=0;i<index;i++)printf("%d \n",Risultato[i]);

   

    system("pause");
    return 0;
}

/*
Complessità: o(n)
Ricorrenza:DP[i]=max2(Seq[i],Seq[i]+DP[i-1]) considero il max tra la sequenza attuale e sequenza attuale+valore precedente
*/