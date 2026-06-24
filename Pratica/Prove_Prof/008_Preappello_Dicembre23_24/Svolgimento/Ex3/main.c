#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    CasoTest ct;
    int Risultato[MAX];
    int Test=0,index=0;
    scanf("%d",&Test);
    //1.Inserimento parametri input
    while (index<Test){
        //A.Definisco budget e classi
        scanf("%d %d",&ct.budget,&ct.Numclassi);
        //B.Inserisco per ogni classe k i vari prodotti
        for (int k = 0; k < ct.Numclassi; k++){
            scanf("%d",&ct.NumProdotti[k]);
            InserisciProdotti(ct.Prodotti[k],ct.NumProdotti[k]);
        }
        //C.Applico la logica DP
        InitDP(DP,ct.Numclassi,ct.budget);
        Risultato[index]=CalcolaDP(DP,ct);
        //D.Passo al caso di test successivo
        index++;
    }
    
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++){
            if (Risultato[i]==-1){
                printf("Denaro insufficiente! \n");
            }else{    
                printf("%d \n",Risultato[i]);
            }
    }
    system("pause");
    return 0;
}

/*
Complessità: O(numeroClassi*Budget*NumeroProdottiPerClasse)

Questo problema rappresenta una variante del problema dello zaino con più oggetti (multi-choice knapsack problem).

Complessità:
Per ogni budget b e per ogni possibile prezzoX, si esegue il seguente controllo:

Se b >= prezzoX e DP[i-1][b-prezzoX] è valido (diverso da -1), allora:

DP[i+1][b] = max(DP[i+1][b], spesaAtt) dove spesaAtt=DP[i-1][b-prezzoX] + prezzoX


*/