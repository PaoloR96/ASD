#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int S[]={2, 3, 5, 6, 8};
    int n=5;
    int target=8;
    
    GeneraCombinazioni(S,n,target);
  
    system("pause");
    return 0;
}
