#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    int k = 0; 
    Involucro T[5];
    int index = 0;
    int nTmp = 0;

    printf("SAMPLE INPUT:\n"); 
    if(scanf("%d", &k) != 1) return 0;
    
    while (index < k) {
        if(scanf("%d", &nTmp) != 1) break;
        if(nTmp == -1) continue; // Salta eventuali -1 fuori posto
        
        T[index].numeroVer = nTmp;
        RiempiCasodiTest(&T[index]);
        
        // Leggiamo il delimitatore -1 che separa i set 
        int delim;
        scanf("%d", &delim); 
        
        index++;
    }
    printf("SAMPLE OUTPUT:\n"); 
    index = 0;
    printf("%d\n", k); // L'output deve iniziare con il numero di casi 
    
    while (index < k) {
        // Ordiniamo per X (tramite Compara) per far funzionare il Dividi et Impera
        qsort(T[index].punto, T[index].numeroVer - 1, sizeof(Punto), Compara);
        
        // Usiamo N-1 punti per evitare il duplicato finale durante i calcoli 
        Involucro risultato = CalcolaConvexHull(T[index].punto, T[index].numeroVer - 1);
        
        ElaboraCasodiTest(risultato);
        index++;
    }
    
    system("pause"); 
    return 0;
}

/*Complessità:O(n*logn)*/