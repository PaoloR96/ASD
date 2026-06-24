#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiCasoTest(CasoTest TestX[MAX_L]) {
    char linea[100];

    for (int i = 0; i < NUMTEST; i++) { //per ogni caso di test
       
        fgets(linea, sizeof(linea), stdin);
        // se l'utente preme solo INVIO → fine input
        if (linea[0] == '\n') break;
        // legge fino a 3 numeri
        TestX[i].quantiNumeri = sscanf(linea, "%d %d %d",&TestX[i].N,&TestX[i].L1,&TestX[i].L2);
        // inizializzo i campi mancanti
        if (TestX[i].quantiNumeri < 2) TestX[i].L1 = 0;
        if (TestX[i].quantiNumeri < 3) TestX[i].L2 = 0;
    }
}


void InizializzaDP(long long DP[MAX_L][MAX_N]){
        //poichè è un problema di conteggio ogni elemento DP[MAX_L][MAX_N] lo pongo a 0
        for (int i = 0; i < MAX_L; i++){
            for (int j = 0; j < MAX_N; j++){
                DP[i][j]=0; 
            }
        } 
}



void ElaboraCasoTest(CasoTest TestX[MAX_L]) {
    long long DP[MAX_L][MAX_N];
    for (int i = 0; i < NUMTEST; i++) { //per ogni caso di test
        //1.Inizializzo la DP
        InizializzaDP(DP);
        //2.Calcolo  DP[MAX_L][MAX_N] popolandola
        CalcolaDP(DP);
        //3. In base a che tipo caso di rientro calcolo il numero di modi
        if(TestX[i].quantiNumeri==1)CalcolaSequenza1(DP,TestX[i].N);
        if(TestX[i].quantiNumeri==2)CalcolaSequenza2(DP,TestX[i].N,TestX[i].L1);
        if(TestX[i].quantiNumeri==3)CalcolaSequenza3(DP,TestX[i].N,TestX[i].L1,TestX[i].L2);
      
    }
}


void CalcolaDP(long long DP[MAX_L][MAX_N]){

        //1.Caso base : DP[0][0]=1
        DP[0][0]=1;
        //2.Ricorrenza:Popolo la matrice DP[MAX_L][MAX_N]
        for (int v = 1; v <= 300; v++){ //per ogni valore di una moneta  
            for (int u = 1; u <= 300; u++){//numero di  moneta usate
                   for (int sommaT = v; sommaT <= 300; sommaT++){ //somma Totale per ottenere v a partire da u
                        DP[u][sommaT]=DP[u][sommaT]+DP[u-1][sommaT-v];
                   }
             }
        }
    
}
//Caso1:Calcolo la somma da k=0 fino a 300,quindi calcolo tutte le combinazioni possibili
void CalcolaSequenza1(long long DP[MAX_L][MAX_N],int N){
    long long SommaTotale=0;
    for (int k = 0; k <= 300; k++)SommaTotale+= DP[k][N];
    printf("%lld\n", SommaTotale);        
}

//Caso2:Calcolo la somma da k=0 fino a L1,quindi calcolo le combinazioni fino ad L1
void CalcolaSequenza2(long long DP[MAX_L][MAX_N],int N,int L1){
    long long SommaTotale=0;
    if (L1 > 300) L1 = 300; // Protezione indice
    for (int k = 0; k <= L1; k++)SommaTotale+= DP[k][N];
    printf("%lld\n", SommaTotale);        
}

//Caso3:Calcolo la somma da k compreso tra L1 Ed L2,quindi calcolo le combinazioni compreso in questo range
void CalcolaSequenza3(long long DP[MAX_L][MAX_N],int N,int L1,int L2){
    long long SommaTotale=0;
    if (L1 > 300) L1 = 300; // Protezione indice
    if (L2 > 300) L2 = 300; // Protezione indice
    for (int k = L1; k <= L2; k++)SommaTotale+= DP[k][N];
    printf("%lld\n", SommaTotale);        
}