#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Risultato[MAX];
    int index=0,Test=0;
    char Stringa[MAX_STINGA];
    scanf("%d",&Test);
    while (index<Test) {
        scanf("%s", Stringa);
        //2.Inizializzo DP
        memset(DP, 0, sizeof(DP));
        int dim=strlen(Stringa);
        InitDP(DP,dim);
        //3.Calcolo DP
        Risultato[index]=CalcolaDP(DP,Stringa,dim);
        //4.Passo al prossimo caso di test
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++)printf("%d \n",Risultato[i]);
    
   
    
    system("pause");
    return 0;
}

/*
Complessità:O(n^2) con n dimensione della stringa
Ricorrenza: Per ogni i € (dim-1,0) && Per ogni j € (i+1,0) abbiamo:
             Se i due caratteri sono ugauli     DP[i][j]=DP[i+1][j-1]+2; //formano un palindromo di lunghezza+2
             Se i due caratteri sono divesi      DP[i][j]=max2(DP[i+1][j],DP[i][j-1]);  //evo fare una scelta, prendendo il massimo


*/