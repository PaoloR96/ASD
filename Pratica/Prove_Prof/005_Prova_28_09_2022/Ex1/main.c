#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h" 

int main() {
    printf("SAMPLE INPUT:\n");
    char Sequenza[MAX];
    int Risultato[MAX], Vett[MAX];
    int i=0;
    
    while (1){
        int index = 0;
        // Fase1: Manipolazione Stringa
        // 1. Se la sequenza è vuota termino
        if(fgets(Sequenza,sizeof(Sequenza),stdin)==NULL)break;
        // 2. Ripulisco da eventuali spazi/newline
        Sequenza[strcspn(Sequenza,"\n\r")] = '\0';
        
        // 3. Esco nel caso leggo END
        if(strcmp(Sequenza,"END") == 0)break;
        
        // 4. Ora devo convertire la stringa in int
        char *ptr=Sequenza;
        char *fine;
        while (*ptr!='\0'){
        
            long temp = strtol(ptr,&fine,10);    
            // Se non ho trovato nessun numero
            if(ptr == fine) break; 
            // Effettuo la conversione e vado avanti
            Vett[index] = temp;
            index++;
            ptr = fine;
        }
        
        // Fase2: Applico il dividi et impera
        // 1. Calcolo la dimensione del vettore
        int dim = index; 
        Risultato[i]=DividiSequenza(Vett,0,dim-1);
        // 2. Passo alla prossima sequenza
        i++;
        
    }

    printf("SAMPLE OUTPUT:\n");
    for (int k = 0; k < i; k++)printf("%d \n",Risultato[k]);
    
    system("pause");
    return 0;
}

/*Complessità: O(test*NlogN)*/