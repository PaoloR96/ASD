#Sudoku
from random import *
N = 9
#############################################################
def StampaGriglia(Val,griglia):
    print()
    print(Val)
    for i in range(N):
        for j in range(N):
                    print(griglia[i][j], end=' ')
        print()
#############################################################
def IsValido(griglia,riga,colonna,num):
    for i in range(N):
        if (griglia[riga][i]==num):
            return False;
    for i in range(N):
        if (griglia[i][colonna]==num):
            return False;
    startCol=colonna -colonna % 3
    startRig=riga -riga % 3
    for i in range(3):
        for j in range(3):
            if (griglia[startRig+i][startCol+j]==num):
             return False;
    return True;




#############################################################

def RisolviSudoku(griglia,riga,colonna):

    #quando arrivo alla fine se è valida questa condizione esco dalla funzione
    if riga ==N-1 and colonna ==N-1 :
            return True;
    #se indice colonna arriva ad N , vuol dire che devo passare alla riga successiva
    #azzerando la colonna, in quanto mi muovo colonna per colonna , fissando la riga
    if colonna==N:
        riga+=1
        colonna=0
    #se la posizione corrente del sudoku contine un numero scorro alla colonna successiva
    if griglia[riga][colonna]>0:
        return RisolviSudoku(griglia,riga,colonna+1)
    #andiamo a generare i possibili valori da inserire nelle varie griglie
    for num in range(1, N + 1, 1):
        if(IsValido(griglia,riga,colonna,num)):

            griglia[riga][colonna]=num
            if(RisolviSudoku(griglia,riga,colonna+1)==True):
                return True;

        #backtraking
        griglia[riga][colonna]=0
    return False;
            
                
#############################################################

if __name__ == "__main__":
    #definisco la griglia e poniamo a 0 tutti gli elementi a 0
    griglia=  [[0 for i in range(N)] for i in range(N)]
    griglia = [[3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0]]
    print("\n")
    StampaGriglia("Stampa griglia iniziale:",griglia)
    if (RisolviSudoku(griglia,0,0)):
            StampaGriglia("Sudoku Completato:",griglia)
    else:
            print("La soluzione non esiste!!")
        