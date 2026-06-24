#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int CalcolaOccorrenza(int A[MAX],int start,int end,int k){
	//1.Condizione di uscita
	if(start==end){
		if(A[end]==k){//elemento trovato
		  return 1; //incremento l'occorrenza  di 1
		}else{
		  return 0;
		}
	}
	//2.Ricorsione
	//Calcolo il punto medio
	int mid=start+(end-start)/2;
	int OccSx=CalcolaOccorrenza(A,start,mid,k);
	int OccDx=CalcolaOccorrenza(A,mid+1,end,k);
	//3.Ritorna il risultato
	return OccSx+OccDx;
}
