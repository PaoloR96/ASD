#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*variabili globali*/
int MaxAssoluto=0;
void TrovaMaxPath(int ListaAdj[NODI][NODI], int visitato[NODI][NODI],int nodoAttuale,int numeroNodi,int lunghezza){
    //Condizione di Uscita:Sono arrivato alla fine,generado un percorso
        if(lunghezza>MaxAssoluto){
            MaxAssoluto=lunghezza;
            return;
    }
    //Bisogna creare il percorso,pertanto per ogni vicino i
    for (int vicino = 0; vicino < numeroNodi; vicino++){
        // Se esiste un arco tra il nodo attuale e il vicino E se l'arco NON è ancora stato percorso
        if (ListaAdj[nodoAttuale][vicino] == 1  && !visitato[nodoAttuale][vicino]){
           //1.Setto visitato a 1
           //NOTA:poichè il grafo non è orientato lo marco in entrambi i lati
           visitato[nodoAttuale][vicino]=1;
           visitato[vicino][nodoAttuale]=1;
           //2.Passo a livello successivo incrementanto la lunghezza di +1 andando a trovare il prossimo nodo
           TrovaMaxPath(ListaAdj,visitato,vicino,numeroNodi,lunghezza+1);
           //3.BACKTRACKING:Setto visitato a 0
           //NOTA:poichè il grafo non è orientato lo marco in entrambi i lati
           visitato[nodoAttuale][vicino]=0;
           visitato[vicino][nodoAttuale]=0;
        }
    }
}