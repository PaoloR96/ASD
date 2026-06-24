#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    char s[10][100001], t[10][100001];
    int index=0;
    while (index<10 && scanf("%s %s", s[index], t[index]) != EOF)index++;
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)CalcolaSottoSequenza(s[i], t[i]);
    
    
    
    

    system("pause");
    return 0;
}

/*Approccio Greedy: Cofronto parola per parola seguendo questa logica: se c1(i)==c2(j) avanzo i altrimenti confronto il prossimo carattere di j
il trucco sta nel non azzerare gli indici
COmplessità:O(m) numero di elementi relativi alla stringa più lunga
*/