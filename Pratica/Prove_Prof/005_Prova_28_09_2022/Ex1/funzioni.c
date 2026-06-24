#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int DividiSequenza(int Vett[MAX],int p,int r){
    //1.Condizione di uscita:Possiamo avere due possibilità
    //Ho un solo elemento
    if (p == r) return Vett[p];
    //Ho sforato la dimensione
    if(p>=r)return 0;
    //2.Andiamo ad applicare l'approccio Dividi Et Impera
    int q=p+(r-p)/2;
    //Valuto gli insiemi sx e dx
    int InsiemeSx=DividiSequenza(Vett,p,q);
    int InsiemeDx=DividiSequenza(Vett,q+1,r);
    //Punto delicato:una parte finisce nella metà sinistra e continua nella metà destra
    int InsimeComune=CalcolaSequenza(Vett,p,q,r);
    //3.Restituisco il massimo tra i tre elementi
    return max2(max2(InsiemeSx,InsiemeDx),InsimeComune);
}

int max2(int a,int b){return(a>b)?a:b;}

int CalcolaSequenza(int Vett[MAX],int p,int q,int r){
        int SommaSx=0;
        int MaxSomma=INT_MIN;
        //Caso1:Mi devo spostare da q verso p (mi sposto verso sx)
        int index=q;
        while (index>=p){
            SommaSx+=Vett[index];
            //Aggiorno la SommaMax di sinistra
            if(SommaSx>MaxSomma)MaxSomma=SommaSx;
            //Passo al carattere successivo
            index--;

        }
        int SommaDx=0;
        int MaxSomma1=INT_MIN;
        //Caso2:Mi devo spostare da q verso r (mi sposto verso dx)
        index=q+1;
        while (index<=r){
            SommaDx+=Vett[index];
            //Aggiorno la SommaMax di destra
            if(SommaDx>MaxSomma1)MaxSomma1=SommaDx;
            //Passo al carattere successivo   
            index++;
        }
        //Ritorna la somma tra i due  MASSIMI 
        return MaxSomma+MaxSomma1;

}