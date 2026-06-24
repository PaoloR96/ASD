#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void RiempiCasiDiTest(CasoTest Test[], int dim) {
    for (int i = 0; i < dim; i++) {
        // Leggo n (amici) e m (amicizie)
        scanf("%d %d", &Test[i].n, &Test[i].m);
        // Inizializzo e leggo i debiti 
        for (int z = 0; z < Test[i].n; z++) {
            scanf("%d", &Test[i].gruppo[z].debito);
            Test[i].gruppo[z].visitato = 0; // Fondamentale per la DFS
            Test[i].gruppo[z].testa = NULL; // Fondamentale per la lista
        }

        // Inserisco le amicizie 
        int x_id, y_id;
        for (int k = 0; k < Test[i].m; k++) {
            scanf("%d %d", &x_id, &y_id);
            // Passiamo l'array del gruppo corrente e i due ID
            aggiungi_amicizia(Test[i].gruppo, x_id, y_id);
        }
    }
}


void ElaboraCasiDiTest(CasoTest Test[],int dim){
        for (int i = 0; i < dim; i++){
            //per ogni caso di test i,esguo i seguenti passi
            int possibile=1; //parto dal presupposto che sia possibile
            int dimN=Test[i].n;
            for (int j = 0; j < dimN; j++){
                int bilancio_gruppo = 0;
                if(!Test[i].gruppo[j].visitato){//Se il gruppo non risulta visitato
                        dfs(j, Test[i].gruppo, &bilancio_gruppo);
                        // Se il bilancio di questo gruppo non è 0, non si può pareggiare
                        if (bilancio_gruppo != 0) {
                            possibile = 0;
                            break; 
                        }
                }
            }
            // Stampa il risultato per il caso di test corrente
            if (possibile) printf("POSSIBLE\n");
            else printf("IMPOSSIBLE\n");
            //passo al caso di test successvio
        }
}







void dfs(int attuale, Persona gruppo[], int *bilancio_gruppo){
        //1. Segno la persona come visitata
        gruppo[attuale].visitato=1;
        //2. Aggiungo il suo debito al bilancio totale del sottogruppo
        *bilancio_gruppo+=gruppo[attuale].debito;
        //3. Devo espolare tutti i suoi amici(vicini)
        Nodo *nodoCorrente=gruppo[attuale].testa;//uso un nodo d'appoggio
        while (nodoCorrente!=NULL){
                int id_amico=nodoCorrente->amico;//selzione l'amico corrente
                if(!gruppo[id_amico].visitato){//se l'amico corrente non è stato ancora visitato
                    dfs(id_amico,gruppo,bilancio_gruppo);// vado ad esplorarlo
                }
                nodoCorrente=nodoCorrente->next; //vado al prossimo nodo
        }
}

















/*Creazione Nodo*/
Nodo * CreateNode(int id){
        //Istanzio il nodo
        Nodo *n=(Nodo*)malloc(sizeof(Nodo));
        if(n!=NULL){//setto il nodo
            n->amico=id;
            n->next=NULL;
        }
        return n;
}

/*Creazione lista di adiacenza delle amicizie*/
void aggiungi_amicizia(Persona gruppo[], int x, int y){
    //Aggiungi y alla lista di x
    //Vado ad allocare un nuovo Nodo per x che punti a y
    
    Nodo *NodoY=CreateNode(y);  //Creo il nodo amico
    //Creo la lista di adiacenza:collego il nodo amico y ad x
    NodoY->next=gruppo[x].testa;
    gruppo[x].testa=NodoY;

    //Aggiungi x alla lista di y
    Nodo *NodoX=CreateNode(x);
    NodoX->next=gruppo[y].testa; 
    gruppo[y].testa=NodoX;

}

