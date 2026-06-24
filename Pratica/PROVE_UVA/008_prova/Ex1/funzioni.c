#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*--variabili globali--*/
int InizioBlocco[MAXN];
int FineBlocco[MAXN];
/*-------------------*/
void CreaVettoreOccorrenze(int Freq[], int a[], int n) {
    int i = 0;
    while (i < n) {
        int j = i;
        // trova fine del blocco di valori uguali
        while (j < n && a[j] == a[i])j++;
        //definisco la frequenza del blocco
        int count = j - i;
        // assegna la frequenza a tutto il blocco
        for (int k = i; k < j; k++){
            Freq[k] = count;
            InizioBlocco[k] = i;
            FineBlocco[k] = j - 1;
        }
        i = j;// Passa al blocco successivo
    }
}
int max3(int a, int b, int c) {
    return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}
// Metodo per trovare il numero di occorrenze del valore più frequente
// p e q sono gli indici della query
int TrovaOccorenze(int Freq[],int a[],int p,int q,int n){
    //Caso 1:Se p e q cadono nello stesso blocco di numeri uguali
    if(a[p]==a[q])return (q-p+1);

    //Caso 2:Altrimenti, dividiamo la query in tre parti(sinistra,centro,destra),pertanto:
    // A. Parte Sinistra: dal punto p alla fine del suo blocco
    int count_sin = FineBlocco[p] - p + 1;
    // B. Parte Destra: dall'inizio del blocco di q fino al punto q
    int count_des = q - InizioBlocco[q] + 1;
    // C. Parte Centrale: cerca il massimo tra i blocchi completi nel mezzo
    int count_cen = 0;
    // L'area centrale va dalla fine del blocco di p all'inizio del blocco di q
    int start_centro = FineBlocco[p] + 1;
    int end_centro = InizioBlocco[q] - 1;
    //saltiamo da blocco a blocco
    for (int m = start_centro; m <= end_centro; m = FineBlocco[m] + 1) {
        if (Freq[m] > count_cen) {
            count_cen = Freq[m];
        }
    }
    // Il risultato è il numero massimo di occorrenze trovato
    return max3(count_sin, count_des, count_cen);
}