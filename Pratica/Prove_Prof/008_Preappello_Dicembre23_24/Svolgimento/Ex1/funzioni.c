#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Necessario per INT_MAX
#include "funzioni.h"

void InserisciMatrice(int Matrice[MAX][MAX], int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d", &Matrice[i][j]);
        }
    }
}

int ComparaElemRiga(const void *a, const void *b){
    int RigaX = *(const int *)a;
    int RigaY = *(const int *)b;
    // Ordino in modo crescente
    return RigaX - RigaY;
}

void OrdinaPerRiga(int Matrice[MAX][MAX], int N, int M){
    for (int i = 0; i < N; i++) qsort(Matrice[i], M, sizeof(int), ComparaElemRiga);
}

int CalcolaDiff(int Matrice[MAX][MAX], int N, int M){
    //Inizializzo al valore massimo,per trovare il minimo
    int DiffAss = INT_MAX; 
    for (int i = 0; i < N - 1; i++){
        int diffLocale = CalcolaSequenza(Matrice[i], Matrice[i+1], N, M);
        //Cerco la differenza minore
        if(diffLocale < DiffAss) DiffAss = diffLocale; 
    }
    return DiffAss;
}

int CalcolaSequenza(int RigaX[MAX], int RigaY[MAX], int N, int M){
    //Inizializzo al valore massimo
    int diffAss = INT_MAX; 
    for (int i = 0; i < M; i++){ 
        int target = RigaX[i];
        int elemento = RicercaBinaria(RigaY, M, target);
        int diffMin = abs(elemento - target);
        if(diffMin < diffAss) diffAss = diffMin; 
    }
    return diffAss;
}

int RicercaBinaria(int RigaX[MAX], int M, int target){
    int low = 0;
    int high = M - 1;
    while (low <= high){
        int mid = low + (high - low) / 2; 
        
        // Caso 1: Coincide con il target
        if (RigaX[mid] == target) return RigaX[mid]; // trovato
        
        // Caso 2: Mi sposto a destra
        if (RigaX[mid] < target){
            low = mid + 1;
        // Caso 3: Mi sposto a sinistra
        } else {
            high = mid - 1;
        }        
    }
    
    // target minore di tutti
    if(high < 0) return RigaX[0];
    
    //target maggiore di tutti
    if(low >= M) return RigaX[M-1];
    
    // Quando il while finisce, 'target' si trova compreso tra RigaX[high] e RigaX[low].
    // Faccio le sottrazioni calcolando le distanze assolute positive per evitare errori.
    if ((target - RigaX[high]) <= (RigaX[low] - target)){
        return RigaX[high];
    } else {
        return RigaX[low];
    }
}