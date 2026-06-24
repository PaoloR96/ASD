#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiCasodiTest(Involucro *t) {
    for (int i = 0; i < t->numeroVer; i++) {
        scanf("%d %d", &t->punto[i].x, &t->punto[i].y);
    }
}

int Compara(const void *a,const void *b){
        Punto * p1=(Punto *)a;
        Punto *p2=(Punto *)b;
        // Se le coordinate Y sono diverse, ordina per Y
        if (p1->y != p2->y) return (p1->y - p2->y); 
        // Se le Y sono uguali, ordina per X
        return (p1->x - p2->x);  
}



void ElaboraCasodiTest(Involucro t) {
    if (t.numeroVer <= 0) return;

    // Trova il punto con Y minima (e X minima di spareggio) 
    int start = 0;
    for (int i = 1; i < t.numeroVer; i++) {
        if (t.punto[i].y < t.punto[start].y || 
           (t.punto[i].y == t.punto[start].y && t.punto[i].x < t.punto[start].x)) {
            start = i;
        }
    }

    // Stampa numero vertici + 1 per la chiusura 
    printf("%d\n", t.numeroVer + 1);
    for (int i = 0; i < t.numeroVer; i++) {
        int idx = (start + i) % t.numeroVer;
        printf("%d %d\n", t.punto[idx].x, t.punto[idx].y);
    }
    // Chiude il contorno 
    printf("%d %d\n", t.punto[start].x, t.punto[start].y);
    printf("-1\n"); // Delimitatore 
}


// Prodotto vettoriale per determinare la direzione della svolta
// Ritorna > 0 per sinistra, < 0 per destra, 0 se collineari
int prodotto_vettoriale(Punto a, Punto b, Punto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


Involucro merge(Involucro L, Involucro R){
        int nL=L.numeroVer;
        int nR=R.numeroVer;
        int a=0,b=0;
        //1.Devo trovare i punti più a Dx e Sx di L ed R
        for (int i = 1; i < nL; i++)if(L.punto[i].x>L.punto[a].x)a=i;
        for (int i = 1; i < nR; i++)if(R.punto[i].x<R.punto[b].x)b=i;
        //2.Calcolo della tangente Superiore
        int indA = a, indB = b;
        int done=0;
        while (!done) {
            done = 1;
            // Spostati su L in senso orario finché la pendenza non smette di salire
            while (prodotto_vettoriale(R.punto[indB], L.punto[indA], L.punto[(indA + 1) % nL]) >= 0) {
                indA = (indA + 1) % nL;
                done = 0;
            }
            // Spostati su R in senso antiorario finché la pendenza non smette di salire
            while (prodotto_vettoriale(L.punto[indA], R.punto[indB], R.punto[(indB - 1 + nR) % nR]) <= 0) {
                indB = (indB - 1 + nR) % nR;
                done = 0;
            }
        }
        //3.Calcolo della tangente Inferiore
        int supA = indA, supB = indB;
        done=0;
        while (!done) {
            done = 1;
            // Spostati su L in senso antiorario
            while (prodotto_vettoriale(R.punto[indB], L.punto[indA], L.punto[(indA - 1 + nL) % nL]) <= 0) {
                indA = (indA - 1 + nL) % nL;
                done = 0;
            }
            // Spostati su R in senso orario
            while (prodotto_vettoriale(L.punto[indA], R.punto[indB], R.punto[(indB + 1) % nR]) >= 0) {
                indB = (indB + 1) % nR;
                done = 0;
            }
       }
       int infA = indA, infB = indB;
       // 4. Costruzione del nuovo Involucro Unito
        Involucro res;
        res.numeroVer = 0;
        // Aggiungi i punti di L dalla tangente superiore alla inferiore (senso antiorario)
        int curr=supA;
        res.punto[res.numeroVer++]=L.punto[curr];//inserisco il punto di partenza
        //inserisco gli altri
        while (curr!=infA){
            curr=(curr+1)%nL;
            res.punto[res.numeroVer++]=L.punto[curr];
        }
        // Aggiungi i punti di R dalla tangente inferiore alla superiore (senso antiorario)
        curr = infB;
        res.punto[res.numeroVer++] = R.punto[curr];//aggiungo il punto di partenza
        //inserisco gli altri
        while (curr != supB) {
            curr = (curr + 1) % nR;
            res.punto[res.numeroVer++] = R.punto[curr];
        }
        return res;

}


Involucro CalcolaConvexHull(Punto pts[], int n) {
    //Caso base: stampo i miei elementi
    if (n <= 3) {
        Involucro base;
        base.numeroVer = n;
        for (int i = 0; i < n; i++) base.punto[i] = pts[i];
        return base;
    }
    //Dividi Et Impera
    int mid = n / 2;
    return merge(CalcolaConvexHull(pts, mid), CalcolaConvexHull(pts + mid, n - mid));
}