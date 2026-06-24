#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
int CalcolaSpostamenti(int A[MAX],int p,int r){
    //1.Condizione di uscita
    if(p>=r)return 0;
    //2.Ricorsione:
    int q=(r+p)/2;//calcolo il punto medio
    //Applico la logica DIVIDI&IMPERA
    int SpostamentiSX=CalcolaSpostamenti(A,p,q);
    int SpostamentiDX=CalcolaSpostamenti(A,q+1,r);
    int Spostamenti=DefinisciSpostamenti(A,p,q,r);
    //Ritorna il numero di spostamenti
    return SpostamentiSX+Spostamenti+SpostamentiDX;

}
int DefinisciSpostamenti(int A[MAX],int p,int mid,int r){
    //1.Definisco i due vettori L ed R
    //a.Calcolo le dimensioni rispettive
    int n1=mid-p+1;
    int n2=r-mid;
    //b.Inizializzo L[p....mid+1] R[mid+1....r]
    int L[n1+1],R[n2+1];
    //2.Vado a riempirli in modo tale da suddividere il vettore di partenza A[p.....mid....r]
    for(int i=0;i<n1;i++)L[i]=A[i+p];
    for(int j=0;j<n2;j++)R[j]=A[j+mid+1];
    //a.Setto le sentinelle
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    //3.Simulo la Fusione per capire gli spostamenti
    int spostamenti=0;
    int i=0,j=0;
    for (int k = p; k<= r; k++){
        /* 
        a.Partendo dal presupposto che L ed R sono ordinati, se R[j] < L[i], 
        * allora R[j] è minore di tutti gli elementi da L[i] a L[n1-1].
        * La formula (n1 - i) calcola il numero di elementi scavalcati 
        * istantaneamente, evitando un ulteriore ciclo di scansione.
        */
        if(L[i]>R[j]){
            A[k]=R[j];
            //b.Calcolo fondamentale: l'elemento in R scavalca tutti quelli rimasti in L
            //Se non siamo sulla sentinella, conta quante posizioni salta
            if (L[i] != INT_MAX) spostamenti = spostamenti + (n1 - i);
            j++;
        }else{
            A[k]=L[i];
            i++;
        }
    }
    return spostamenti;        
    
}
