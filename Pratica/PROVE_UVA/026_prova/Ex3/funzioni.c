#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void RiempiBlocchi(Blocco B[MAX], int n_tipi) {
    int x, y, z;
    int k = 0; 
    for (int i = 0; i < n_tipi; i++) {
        // Leggiamo i tre lati del tipo di blocco i 
        scanf("%d %d %d", &x, &y, &z);

        // Variante 1: Altezza x, base (y,z) 
        B[k].h = x;
        B[k].lunghezza = (y > z) ? y : z;
        B[k].larghezza = (y > z) ? z : y;
        B[k].base = B[k].lunghezza * B[k].larghezza;
        k++;

        // Variante 2: Altezza y, base (x,z) 
        B[k].h = y;
        B[k].lunghezza = (x > z) ? x : z;
        B[k].larghezza = (x > z) ? z : x;
        B[k].base = B[k].lunghezza * B[k].larghezza;
        k++;

        // Variante 3: Altezza z, base (x,y) 
        B[k].h = z;
        B[k].lunghezza = (x > y) ? x : y;
        B[k].larghezza = (x > y) ? y : x;
        B[k].base = B[k].lunghezza * B[k].larghezza;
        k++;
    }
}
//Metodo di comparazione:Usato per aiutare il qsort ad ordinare il base alla base di ogni blocco
int ComparaBlocchi(const void *a,const void* b){
    Blocco *b1=(Blocco*)a;
    Blocco *b2=(Blocco*)b;
    // Ordinamento decrescente basato sull'area della base
    if(b2->base > b1->base) return 1;
    if(b2->base < b1->base) return -1;
    return 0;
}

/*VARIBILE GLOBALE*/
int DP_H[MAX];
/*................*/
// Inizializzazione: ogni blocco i è una torre alta quanto B[i].h
void InitDP(int DP_H[MAX],Blocco B[MAX],int dim){
    for (int i = 0; i < dim; i++)DP_H[i] = B[i].h;;
}
int CalcolaDP(int DP_H[MAX],Blocco B[MAX],int numB){
    int maxTotale = 0;
    for (int i = 0; i < numB; i++){ //Per ogni blocco iesimo devo confrontarlo con i precendeti
        int lunghezzax=B[i].lunghezza;
        int larghezzax=B[i].larghezza;
        int hx=B[i].h;
        int posBloccoAtt=i;
        // Il blocco attuale i tenta di appoggiarsi su un blocco j precedente
        for (int j = 0; j <posBloccoAtt; j++){
            // Condizione: base di i strettamente minore della base di j
            if(lunghezzax<B[j].lunghezza && larghezzax<B[j].larghezza ){
                DP_H[i]=max2(DP_H[i],DP_H[j] + B[i].h);
            }
        }
        //Aggiorno il massimo globale ad ogni passo
        if(DP_H[i]>maxTotale)maxTotale = DP_H[i];
    }
    return maxTotale;
}


int max2(int a,int b){
    return (a>b)? a:b;
}
