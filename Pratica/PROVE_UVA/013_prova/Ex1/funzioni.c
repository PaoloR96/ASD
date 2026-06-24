#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int max3(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}


int DividiInsieme(int V[],int p, int r){
        //Caso base: abbiamo un solo elemento
        if(p==r)return V[p];
        //Ricorrenza sugli n elementi
        int q=(p+r)/2;//calcolo il punto medio
        int SommaSx=DividiInsieme(V,p,q);
        int SommaDx=DividiInsieme(V,q+1,r);
        int SommaCentrale=Risolvi(V,p,q,r);       
        return max3(SommaSx,SommaCentrale,SommaDx);
}


int Risolvi(int V[],int p, int q,int r){
    int maxSx=INT_MIN,maxDx=INT_MIN;
    int sommaSx=0,sommaDx=0;
    //vado da p a q
    for(int i=q;i>=p;i--){
        sommaSx+=V[i];
        if(sommaSx>maxSx)maxSx=sommaSx;//salvo il massimo locale
    }
    //vado da q+1 a r
    for(int i=q+1;i<=r;i++){
        sommaDx+=V[i];
        if(sommaDx>maxDx)maxDx=sommaDx;//salvo il massimo locale
    }
    return maxDx+maxSx;
}