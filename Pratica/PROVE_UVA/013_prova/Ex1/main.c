#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int V[]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n=sizeof(V)/sizeof(V[0]);
    printf("SAMPLE INPUT:\n");
    for (int i = 0; i < n; i++)printf("%d\n",V[i]);
    printf("SAMPLE OUTPUT:\n");
    int val= DividiInsieme(V,0,n-1);
    printf("%d \n",val);

    
   

    system("pause");
    return 0;
}

/*Complessita: O(n*logn)*/