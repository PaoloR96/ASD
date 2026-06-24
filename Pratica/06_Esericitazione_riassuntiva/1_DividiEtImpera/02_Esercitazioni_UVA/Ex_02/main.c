#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    int mn[SIZE][2];
    int index = 0;

    printf("SAMPLE INPUT:\n");

    while (1) {
        scanf("%d %d", &mn[index][0], &mn[index][1]);

        if (mn[index][0] == 1 && mn[index][1] == 1)
            break;

        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    CalcolaSequenze(mn, index);

    system("pause");
    return 0;
}
/*Complessità O(logn)*/