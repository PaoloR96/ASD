#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
  int n = 10;
    // Inizializza l'array con -1
    for (int i = 0; i < MAX; i++)memo[i] = -1;

    printf("Fibonacci(%d) = %lld\n", n, fib(n));



    system("pause");
    return 0;
}
