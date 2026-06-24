#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
int max2(int a,int b){return (a>b)?a:b;}
int DividiSequenza(int A[MAX],int p,int r){
    //1.Condizione di uscita
    if(p>r)return INT_MIN;
    //2.Caso base:Ho un solo elemento
    if(p==r)return  A[p];
    //3.Applico il Dividi Et Impera
    int mid=p+(r-p)/2;
    int InsiemeSx=DividiSequenza(A,p,mid);
    int InsiemeDx=DividiSequenza(A,mid+1,r);
    //4.Calcolo il punto incrociati ossia (x1...q.....x2)
    int InsiemeCC= CalcolaSomma(A,p,mid,r);
    //5.Ritorna il valore max:Ritorna la somma max tra i tre punti analizzati
    return max2(max2(InsiemeSx,InsiemeDx),InsiemeCC);
}
int CalcolaSomma(int A[MAX],int p,int q,int r){
    //Fase1:Calcolo la somma dell'insime di sinstra (q,p):Parto da q e mi sposto verso p
    int MaxSommaSx=0,MaxSx=INT_MIN;
    int i=q;
    while (i>=p){
        MaxSommaSx+=A[i];
        if(MaxSommaSx>MaxSx)MaxSx=MaxSommaSx;
        i--;
    }
    //Fase2:Calcolo la somma dell'insime di destra (p,r):parto da q e mi sposto a destra verso r
    int MaxSommaDx=0,MaxDx=INT_MIN;
    i=q+1;
    while (i<=r){
        MaxSommaDx+=A[i];
        if(MaxSommaDx>MaxDx)MaxDx=MaxSommaDx;
        i++;
    }
    //Fase 3:ritorna la somma massima tra MaxDx e MaxSx
    return (MaxDx+MaxSx);
}
