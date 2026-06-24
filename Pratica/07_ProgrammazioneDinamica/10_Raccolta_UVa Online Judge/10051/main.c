#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int dp[N][C];
    Parent parent[N][C];
    int numeroCubi = 3; 

    // Definizione dei capi come da Sample Input 1 
    Cubo A[] = {
        {1, {1,2,2,2,1,2}},       
        {2, {3,3,3,3,3,3}},        
        {3, {3,2,1,1,1,1}}  
    };

    printf("SAMPLE INPUT:\n");
    StampaInput(A, numeroCubi);
    //1.Inizializzazione Matrice dp[numeroCubi][C]
    InitDP(dp,parent,numeroCubi);
    // 2. Calcolo maxH e coordinate di partenza
    int startI, startF;
    int maxH = CalcolaDP(dp, parent, A, numeroCubi, &startI, &startF);
    printf("%d\n", maxH); // Stampa altezza torre
    // 3. Stampa Torre: passiamo i VALORI contenuti in startI e startF
    stampaTorre(parent, startI, startF);
   

    system("PAUSE");
    return 0;
}

/*

Complessità:O(N^2 * C^2)
La complessità deriva dai quattro cicli for annidati che abbiamo discusso:

Primo ciclo (N):
Scorri tutti i cubi i (da 0 a N-1).

Secondo ciclo (C):
Per ogni cubo i, provi tutte le sue 6 facce come "Top".

Terzo ciclo (N):
Per ogni faccia, cerchi tra tutti i cubi precedenti j (da 0 a i-1).

Quarto ciclo (C):
Per ogni cubo precedente j, controlli tutte le sue 6 facce come potenziale incastro.

Ricorrenza:DP[i][f] = 1 + max( {0} ∪ { DP[j][f_prev] } )

Con DP[i][f] l'altezza massima di una torre che ha come cubo alla base il cubo i con la faccia f rivolta verso l'alto.

Caso Base:
    Ogni faccia di ogni cubo è, potenzialmente, la base di una torre alta 1.
    All'inizio, ogni cubo "pensa" di essere solo.

B. La Ricerca del "Socio" Migliore
Quando esaminiamo il cubo i (più pesante), guardiamo tutti i cubi j che sono stati processati prima (più leggeri).
Per ogni possibile orientamento del cubo sopra (f_prev), controlliamo se il suo "sedere"
(faccia opposta a quella superiore) ha lo stesso colore della "testa"
(faccia f) del nostro cubo attuale.

C. La Scelta Ottima
Se troviamo più cubi leggeri che possono stare sopra il nostro cubo attuale,
non li prendiamo tutti. Scegliamo quello che aveva già costruito la torre più alta fino a quel momento.

Se il cubo j faceva parte di una torre alta 3, il nostro cubo i si mette sotto e dichiara:
"Adesso la torre è alta 3 + 1 = 4".

Salviamo questa decisione nel Parent per ricordarci che, per fare 4,
siamo passati dal cubo j.
*/