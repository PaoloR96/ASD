#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file 

/*VARIABILE GLOBALE*/
extern int contatoreSoluzioni;

/*METODI*/

/*Con questo metodo verifico se la riga da provare rispetta le due proprità:
1)Se la rigaDaProvare è già presente all'interno della sequenza
2)Controllo Diagonale:|R1 - R2| == |C1 - C2|
Se questo due proprità sono verificate il metodo ritorna 1 */
int IsSicuro(int Soluzione[], int colonnaAttuale, int rigaDaProvare){
        for (int i = 0; i < colonnaAttuale; i++){//for che copre l'intervallo (pos0,colonnaAttuale)
            //Proprietà 1:
            if(Soluzione[i]==rigaDaProvare)return 0; //c'è conflitto
            //Prorprità 2:
            if (abs(Soluzione[i] - rigaDaProvare) == abs(i - colonnaAttuale)) return 0; // c'è conflitto
        }
        return 1;//non c'è conflitto
}
/*Stampa Soluzioni*/
void StampaSoluzione(int Soluzione[]) {
    if (contatoreSoluzioni == 1) {
        printf("SOLN       COLUMN\n"); 
        printf(" #      1 2 3 4 5 6 7 8\n\n"); 
    }
    printf("%2d      ", contatoreSoluzioni); 
    for (int i = 0; i < 8; i++) {
        printf("%d%s", Soluzione[i], (i < 7 ? " " : "")); 
    }
    printf("\n"); 
}


/*Logica di BackTracking*/
void CalcolaSoluzione(int Soluzione[], int index, int rx, int cx){
        //Condizione di uscita:Ho generato la combinazione
        if(index==8){
            StampaSoluzione(Soluzione);
            contatoreSoluzioni++;
            return;
        }
        //Ricorsione:
        //1.Se siamo nella colonna stabilita dall'input
        if(index==(cx-1)){
            // Verifichiamo se la riga fissata rx è sicura rispetto alle regine precedenti
            if(IsSicuro(Soluzione,index,rx)){
                Soluzione[index]=rx;
                CalcolaSoluzione(Soluzione,index+1,rx,cx);
            }
            return;
        }
        //2.Altrimenti proviamo tutte le righe da 1 a 8 per la colonna corrente
        for (int i = 1; i <= 8; i++){
            if (IsSicuro(Soluzione,index,i)){
                Soluzione[index] = i; // Piazza la regina nella riga i
                CalcolaSoluzione(Soluzione,index+1,rx,cx);// Passa alla colonna successiva
                // Backtracking: l'assegnazione verrà sovrascritta nel prossimo ciclo del for
            }           
        }
}