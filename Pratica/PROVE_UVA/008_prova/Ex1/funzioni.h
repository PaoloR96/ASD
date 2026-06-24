#ifndef FUNZIONI_H
#define FUNZIONI_H
// Definiamo i limiti basati sul testo del problema
#define MAXN 100005
// Variabili globali di supporto 
extern int InizioBlocco[MAXN];
extern int FineBlocco[MAXN];
//////////////////////////////////////
#endif
void CreaVettoreOccorrenze(int Freq[], int a[], int n);
int TrovaOccorenze(int Freq[],int a[],int p,int q,int n);
int max3(int a, int b, int c);
