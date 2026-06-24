#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int RicercaLowerBound(int Colonna[],int m,int L){
    int jmin=-1;
    int low=0;
    int high=m-1;

    while (low<=high){
        //1.Calcolo il punto medio
        int mid = low + (high - low) / 2;
        //2.Se soddisffa la condizione ho trovato jmin
        if(Colonna[mid]>=L){
            jmin=mid;
            high=mid-1;//Cerco di trovare più a sx
        }else{
            //Mi sposto a dx
            low=mid+1;
        }
    }
    //3.Ritorna il mio indice
    return jmin;
}
int CalcolaArea(int Matrice[N][M],int m,int n,int L,int U){
        int max_area=0;
        for (int i = 0; i < n; i++){
            //Passo1:Trovo il mio indice di partenza
            int jmin=RicercaLowerBound(Matrice[i],m,L);
            if(jmin!=-1){
                //Passo2:Devo costruire il quadrante a partire da J min
                // Sfruttiamo la proprietà: se l'angolo in basso a destra è <= U, tutto il quadrato è <= U.
                while (i+max_area<n && jmin+max_area<m && Matrice[i+max_area][jmin+max_area]<=U)max_area++;
            }
        }
        //3.Ritorna la maxArea
        return max_area;
}

void RiempiMatrice(int Matrice[N][M],int n,int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d",&Matrice[i][j]);
        }
    }
}


void  CalcolaCasoTestX(int Matrice[N][M],int m,int n, Query q[1000],int dim,int index){
    printf("SAMPLE OUTPUT%d: \n",index+1);
    for (int i = 0; i < dim; i++){
        int val=CalcolaArea(Matrice,m,n,q[i].x,q[i].y);
        printf("%d \n",val);
    }
    printf("- \n");
}


Complessità: =(k*logn) con  k=numeroTest*dimQuery*numeroRIghe