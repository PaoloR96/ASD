#ifndef FUNZIONI_H
#define FUNZIONI_H

#define SIZE 50

// Prototipi delle funzioni
void RiempiVettore(int A[], int size);
int TrovaMassimo(int A[], int size);
int SommaTotale(int A[], int size);
void CalcolaSequenze(int A[][SIZE], int size[], int k[], int index);
int contaScribi(int libri[], int size, int caricoMassimo, int indiceCorrente, int scribiCorrenti, int caricoCorrente);
int VerificaMassimoCarico(int libri[], int size, int k, int caricoMassimo);
int RicercaBinaria(int libri[], int size, int k, int minCarico, int maxCarico);
void StampaDivisione(int libri[], int size, int k);

#endif
