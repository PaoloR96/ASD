#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Test=0;
    Risultato ris[100];
   /*
    n=capienza traghetto
    t= tempo per percorrere la tratta
    m=numero di auto presenti
    Tempi[100] = orario arrivo auto
    */
    int n=0,m=0,t=0;
    int Tempi[100];
    scanf("%d",&Test);
    for (int i = 0; i < Test && i<100; i++){
        scanf("%d %d %d ",&n,&t,&m);
        //Inserisco gli orari di arrivo per ogni auto
        for(int i=0;i<m;i++)scanf("%d",& Tempi[i]);
        //Calcolo il numero di viaggi ed il tempo necessario
        ris[i]=CaricaTraghetto(n,t,m,Tempi); 

    }
    
    printf("SAMPLE OUTPUT: \n");
      for (int i = 0; i < Test; i++)printf("%d %d \n",ris[i].TempoMin,ris[i].numeroViaggi);
   

    system("pause");
    return 0;
}

/* 
 * Analisi della complessità: O(m) con m = numero di auto.
 * Nonostante i cicli annidati, l'indice 'i' scorre l'array linearmente.
 * Ogni auto viene processata una sola volta, rendendo il contributo 
 * del ciclo interno distribuito (ammortizzato) su tutta l'esecuzione.
 */