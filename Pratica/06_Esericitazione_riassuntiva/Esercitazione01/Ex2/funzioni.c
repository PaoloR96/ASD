#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int cont=0;
void CalcolaSequenza(int num,int i, bool used[]){
    /*caso base:uscita*/
    if (i>num){
        cont++;
        return;
    }else{
        // Se l'elemento i è già accoppiato, passa al successivo
        if (used[i]){
           CalcolaSequenza(num,i+1,used);
           return;
        }
         // Caso 1: i resta single
          used[i] = true;
          CalcolaSequenza(num,i+1,used);
           used[i] = false; //backtracking
         // Caso 2: i si accoppia con un altro elemento j > i
         for (int j = i + 1; j <= num; j++) {
            if (!used[j]) {
                used[i] = used[j] = true;
                CalcolaSequenza(num, i + 1, used);
                used[i] = used[j] = false;//backtracking
            }
        }
        
    }

}
void GeneraSequenza(int num){
    bool used[num+1];
    for (int i = 0; i <= num; i++)used[i]=false;
    CalcolaSequenza(num,1,used);
    printf("Numero totale di modi: %d\n", cont);




}