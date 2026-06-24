#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>      // Necessario per exp(), sin(), cos(), tan(), fabs()
#include "funzioni.h"

/*
 * CalcolaFunzione:
 * - Riceve una matrice A[dim][6], dove ogni riga contiene i coefficienti
 *   p, q, r, s, t, u dell'equazione:
 *
 *     f(x) = p*e^{-x} + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 + u
 *
 * - Per ogni riga chiama la bisezione per trovare la radice nell’intervallo [0,1].
 */
void CalcolaFunzione(double test_cases[MAX_TESTS][6], int dim) {

    for (int i = 0; i < dim; i++) {
        double p = test_cases[i][0];
        double q = test_cases[i][1];
        double r = test_cases[i][2];
        double s = test_cases[i][3];
        double t = test_cases[i][4];
        double u = test_cases[i][5];
        // Calcolo funzione agli estremi dell'intervallo
        double f0 = f(0.0, p, q, r, s, t, u);
        double f1 = f(1.0, p, q, r, s, t, u);

        /*
         * Se f(0) e f(1) hanno lo stesso segno, non c’è garanzia
         * di una radice nell'intervallo secondo il teorema degli zeri.
         */
        if (f0 * f1 > 0) {
            printf("No solution\n");
            continue;
        }

        // Chiamata al metodo della bisezione ricorsiva
        double result = Bisezione(0.0, 1.0, 1e-7, p, q, r, s, t, u);

        // Stampa del risultato con 4 cifre decimali
        printf("%.4f\n", result);
    }
}


double f(double x, double p, double q, double r, double s, double t, double u) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

/*
 * Bisezione:
 * - Prende un intervallo [low, high]
 * - Prende la precisione eps
 * - Ritorna una radice della funzione f(x) con i coefficienti p,q,r,s,t,u
 *
 * Metodo:
 * - Calcola midpoint
 * - Determina in quale metà dell'intervallo si trova la radice
 * - Chiama ricorsivamente la funzione fino a ottenere una precisione sufficiente
 */
double Bisezione(double low, double high, double eps,double p, double q, double r, double s, double t, double u){
        double mid = (low + high) / 2.0;
        // Valore della funzione nel punto medio
        double fmid = f(mid, p, q, r, s, t, u);
        // Caso base della ricorsione: la radice è abbastanza precisa
        if (fabs(fmid) < eps)return mid;
        // Valuto f(low) per determinare in quale metà procede la bisezione
        double flow = f(low, p, q, r, s, t, u);

        // Se f(low) e f(mid) hanno segno diverso → radice in [low, mid]
        if (flow * fmid < 0)
            return Bisezione(low, mid, eps, p, q, r, s, t, u);
        else
            // Altrimenti la radice sta in [mid, high]
            return Bisezione(mid, high, eps, p, q, r, s, t, u);
}
