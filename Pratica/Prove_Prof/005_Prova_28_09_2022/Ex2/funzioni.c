#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaTriangolo(int n){
    int riga_effettiva=n-1;
    for (int k = 0; k <=riga_effettiva; k++){
        int val=CalcolaTriangolo(riga_effettiva,k);
        printf("%d \t",val);
    }
    printf("\n");
}
int CalcolaTriangolo(int riga,int col){
        //Caso base (i bordi del triangolo sono sempre 1)
        if(col==0|| col==riga)return 1;
        // Passo ricorsivo: "esploro" i rami superiori
        return CalcolaTriangolo(riga-1,col-1)+CalcolaTriangolo(riga-1,col);
}