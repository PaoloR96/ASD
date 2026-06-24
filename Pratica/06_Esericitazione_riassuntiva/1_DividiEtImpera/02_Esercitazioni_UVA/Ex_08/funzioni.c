#include <stdio.h>
#include "funzioni.h"


// Funzione per trovare il gruppo k usando ricorsione sicura
long long RicercaElemento(long long low, long long high, long long i) {
    if (low > high) return low; // gruppo trovato
    long long mid = (low + high) / 2;
    if (mid * (mid + 1) / 2 < i)
        return RicercaElemento(mid + 1, high, i);
    else if ((mid - 1) * mid / 2 >= i)
        return RicercaElemento(low, mid - 1, i);
    else
        return mid;
}

// Funzione per calcolare la posizione relativa all’interno del gruppo
void TrovaK(long long A[], long long size) {
    for (long long j = 0; j < size; j++) {
        long long k = RicercaElemento(1, A[j], A[j]); // trova il gruppo k
        long long L_prev = (k - 1) * k / 2; // lunghezza cumulativa fino a k-1
        long long pos_relativa = A[j] - L_prev; // posizione relativa dentro il gruppo
        printf("%lld\n", pos_relativa);
    }
}
