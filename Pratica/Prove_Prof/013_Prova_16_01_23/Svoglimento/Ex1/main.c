#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Ris[MAX],V[MAX];
    int index=0,test=0,dim=0;
    scanf("%d",&test);
    for (int i = 0; i < test; i++){
        //Fase1:Inserimento valori
        scanf("%d",&dim);
        RiempiVettore(V,dim);
        //Fase2:Calcolo la mediana
        int mediana=V[dim/2];
        //Fase3:Ordino gli elementi
        qsort(V,dim,sizeof(int),ComparaElementi);
        //Fase4:Calcolo la distanzaTotale
        Ris[i]=TrovaDistanza(V,dim,mediana);

    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < test; i++)printf("%d\n",Ris[i]);
    
    system("pause");
    return 0;
}
/*Complessità: O(Test*M*logM)*/