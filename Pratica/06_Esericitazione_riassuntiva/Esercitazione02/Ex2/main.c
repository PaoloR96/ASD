#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int A[4]={4,5,6,8};
    for(int i=0;i<4;i++)TrovaSoluzioni(i,A[i]);


    system("pause");
    return 0;
}
