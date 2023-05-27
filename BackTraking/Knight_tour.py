# Dimensione scacchiera n*n
n = 8
 
 
def isCorretta(x, y, scacchiera):
    
    #controllo se gli indici x ed y generati sono validi per la scacchiera n*n
    if(x >= 0 and y >= 0 and x < n and y < n and scacchiera[x][y] == -1):
        return True
    return False
 
 
def StampaScacchiera(Val,scacchiera):
    print()
    print(Val)
    for i in range(n):
        for j in range(n):
                    print(scacchiera[i][j], end=' ')
        print()
 
 
def CalcolaPercorsoL(scacchiera):

    #definisco le coordinate di movimento del cavaliere rispetto ad x ed y dove andiamo a definire 
    #tutti i possibili movimenti
    move_x = [2, 1, -1, -2, -2, -1,  1, 2]
    move_y = [1, 2, 2, 1,   -1,   -2, -2, -1]
    
    

    #posizione corrente cavaliere
    pos = 1
 
    # Controllo se la soluzione esiste
    if(CalcolaMossa(n, scacchiera, 0, 0, move_x, move_y, pos)):
        StampaScacchiera("SOluzione", scacchiera)
    else:
        print("La soluzione non esiste")
        
 
 
def CalcolaMossa(n,scacchiera, curr_x, curr_y, move_x, move_y, pos):

    #se ho consumato tutte le n^2 soluzioni esco dal ciclo e ritorna true
    if((pos == n**2)):
        return True
 
    # Calcolo le nuove mosse partendo dalle coordinate x, y correnti
    for i in range(n):
        new_x = curr_x + move_x[i]
        new_y = curr_y + move_y[i]
        if(isCorretta(new_x, new_y, scacchiera)):
            #marco la cella con pos
            scacchiera[new_x][new_y] = pos
            #ricalcolo la prossima mossa
            if(CalcolaMossa(n, scacchiera, new_x, new_y, move_x, move_y, pos+1)):
                return True
 
            # Backtracking
            scacchiera[new_x][new_y] = -1
    return False
 
 
# Driver Code
if __name__ == "__main__":
     
    #genero la scacchiera tutti i valori a -1
     scacchiera = [[-1 for i in range(n)]for i in range(n)]
     #pongo a 0 la pos [0][0] in maniera tale da inizializzare dove inizierò la mia mossa
     scacchiera[0][0] = 0
     StampaScacchiera("Stato iniziale",scacchiera)
     CalcolaPercorsoL(scacchiera)