#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"

void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) scanf("%d",&A[i]);
}

int TrovaMassimo(int A[], int size){
    int max=A[0];
    for (int i = 1; i < size; i++){
         if(A[i]>max) max=A[i];
    }
    return max;
}

int SommaTotale(int A[], int size){
    int somma=0;
    for (int i = 0; i < size; i++) somma+=A[i];
    return somma;
}

/*Conta gli scribi necessari ricorsivamente*/
int contaScribi(int libri[], int size, int caricoMassimo, int indiceCorrente, int scribiCorrenti, int caricoCorrente) {
    if(indiceCorrente >= size) return scribiCorrenti;
    int libro = libri[indiceCorrente];
    if(libro > caricoMassimo) return INT_MAX;
    if(libro + caricoCorrente <= caricoMassimo)
        return contaScribi(libri, size, caricoMassimo, indiceCorrente+1, scribiCorrenti, caricoCorrente + libro); //passo al libro successivo aggiornando il carico
    else
        return contaScribi(libri, size, caricoMassimo, indiceCorrente+1, scribiCorrenti+1, libro);//aggiungo un nuovo scriba
}

/* Verifica se un massimo carico è possibile */
int VerificaMassimoCarico(int libri[], int size, int k, int caricoMassimo){
    int scribiUsati = contaScribi(libri, size, caricoMassimo, 0, 1, 0);
    return (scribiUsati <= k);
}

/*Ricerca Binaria*/
int RicercaBinaria(int libri[], int size, int k, int minCarico, int maxCarico) {
    if(minCarico >= maxCarico) return minCarico;
    int mid = (minCarico + maxCarico)/2;
    if(VerificaMassimoCarico(libri, size, k, mid))
        return RicercaBinaria(libri, size, k, minCarico, mid);
    else
        return RicercaBinaria(libri, size, k, mid+1, maxCarico);
}

/* Stampa la divisione finale con slash */
void StampaDivisione(int libri[], int size, int k) {
    int maxCarico = RicercaBinaria(libri, size, k, TrovaMassimo(libri, size), SommaTotale(libri, size));
    
    int carico = 0;
    int scribiRimanenti = k;
    
    for(int i = 0; i < size; i++) {
        int libriRimanenti = size - i;
        
        // Serve chiudere la parte corrente?
        if(carico + libri[i] > maxCarico || libriRimanenti == scribiRimanenti) {
            if(carico > 0) {           // solo se c'è qualcosa da chiudere
                printf("/ ");
                scribiRimanenti--;
                carico = 0;
            }
        }
        
        printf("%d", libri[i]);
        carico += libri[i];
        
        if(i != size-1) printf(" ");
    }
    printf("\n");
}


/* Ciclo su tutti i casi e stampa il risultato */
void CalcolaSequenze(int A[][SIZE], int size[], int k[], int index){
    for (int i = 0; i < index; i++){
        StampaDivisione(A[i], size[i], k[i]);
    }
}
