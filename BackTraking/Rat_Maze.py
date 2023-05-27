#dimensione labirinto
n = 4
def StampaLabirinto(Val,labirinto):
    print()
    print(Val)
    for i in range(n):
        for j in range(n):
                    print(labirinto[i][j], end=' ')
        print()


def CheckPasso(n,labirinto,labSoluzioni,x,y):
    # se x ed y sono positivi e sono contenuti in n  e se nel labirinto ho via libera (1) e allo stesso tempo
    #labSoluzioni è 0 vuol dire che x ed y sono coordinate utili per generare il mio percorso
    #pertanto ritorna true
    if((x>=0 and y>=0)and(x<n and y<n) and (labirinto[x][y]==1) and (labSoluzioni[x][y]==0)):
        
        return True;
    return False;





def CalcolaPercorso(n,labirinto,labSoluzioni,movie_x,movie_y,x,y):
    
    #prima di tutto vedo a che posizione sto 
    if x==n-1 and y==n-1 :
        return True;
    #andiamo a generare  un possibile percorso 
    for i in range(n):
                #genero un valore x ed y
                new_x=x+movie_x[i]
                new_y=y+movie_y[i]
                #ora li vado a controllare se questi due valori sono una possibile soluzione nel caso labirinto[new_x][new_y]
                if (CheckPasso(n,labirinto,labSoluzioni,new_x,new_y)):
                  #se è verificato valido con uno la nuova pozione new_x, new_y
                  labSoluzioni[new_x][new_y]=1;
                  #dopo aver salvato questa soluzione richiamo in maniera ricorsiva CalcolaPercorso, dandogli al posto di x ed y
                  #x_new ed y_new che corrispondono alle nuove coordinate del punto in cui sono passato
                  #chiamo in maniera ricorsiva CalcolaPercorso, se la condizione è verifacata return true
                  if(CalcolaPercorso(n,labirinto,labSoluzioni,movie_x,movie_y,new_x,new_y)):return True;
                  #se non verificata sono sicuro che per di li non posso passare pertanto porrò la nuova coordinata a 0
                  #backtraking
                  labSoluzioni[new_x][new_y]=0;
    return False;
                  

def DefinisciPercorso(labirinto):
        #creo labSoluzioni per andare a ricercare le possibili soluzioni
        #l'unica cosa che conosco è che parto dalla posizione [0,0]
        labSoluzioni = [[0 for i in range(n)] for i in range(n)]
        labSoluzioni[0][0] = 1
        StampaLabirinto("Stampa labSoluzioni: ",labSoluzioni)
        #definisco le matrice delle direzioni rispetto ad x ed y
        movie_x=[-1, 1, 0, 0]
        movie_y = [0, 0, -1, 1]
       
        if(CalcolaPercorso(n,labirinto,labSoluzioni,movie_x,movie_y,0,0)):
            
            StampaLabirinto("Stampa Soluzione",labSoluzioni)
        else:
            print('Nessuna Soluzione Trovata!!')
        






if __name__ == "__main__":
    #definisco il labirinto dove 1 rappresenta l'accesso e 0 rappresenta il muro
    labirinto = [[1, 0, 0, 0],
             [1, 1, 0, 1],
             [0, 1, 0, 0],
             [1, 1, 1, 1]]
    StampaLabirinto("Stampa labirinto: ",labirinto)
    print("\n")
    DefinisciPercorso(labirinto)