#l'idea è quella di creare un labiritno (a partire da quello dato in input) nel quale si sotituiscono le celle adiacenti (nelle quattro direzioni) ad uno
# 0 con -1 in modo da segnalare un "muro". Partedo da questo labirinto, e controllando per ogni ingresso e ogni uscita, effettuo il backtracking per trovare il 
#percorso. Infine stampo la minima somma dei cammini trovati. 
#l'algoritmo implementato non riesce a trovare in tuttii casi il percorso minimo perchè non considera errato il percorrere due percorsi paralleli es:[0,1,1,1,1,
#                                                                                                                                                     1,1,1,1,0,
#                                                                                                                                                     0,0,0,0,0]
#in questo caso può perorrere il cammino a zig zag e trovare l'uscita senza considerare di star facendo dei passi in più


def StampaLabirinto(Val,labirinto,R,C):
    print()
    print(Val)
    for i in range(R):
        for j in range(C):
                    print(labirinto[i][j], end=' ')
        print()


def CheckPasso(R,C,labirinto,labSoluzioni,r,c):
    # controllo se le cordinate rispettano i parametri della traccia e del labirinto
    if((r>=0) and(r<R) and (c==C-1) and (labSoluzioni[r][c]==1)):
        return True
    
    if((r>=0 and c>0)and(r<R and c<C-1) and (labirinto[r][c]==1) and (labSoluzioni[r][c]==0)):
        
        return True
    return False





def CalcolaPercorso(R,C,labirinto,labSoluzioni,movie_x,movie_y,r,c):
    
    if c==C-1 and labirinto[r][c] == 1:
        return True
    
    #andiamo a generare  un possibile percorso 
    for i in range(3):
        new_x=r+movie_x[i]
        if(movie_x[i] == 0):
            for j in range(3):
                new_y=c+movie_y[j]
                #ora li vado a controllare se questi due valori sono una possibile soluzione nel caso labirinto[new_x][new_y]
                if (CheckPasso(R,C,labirinto,labSoluzioni,new_x,new_y)):
                    #se è verificato valido con uno la nuova pozione new_x, new_y
                    labSoluzioni[new_x][new_y]=1
                    #dopo aver salvato questa soluzione richiamo in maniera ricorsiva CalcolaPercorso, dandogli al posto di x ed y
                    #x_new ed y_new che corrispondono alle nuove coordinate del punto in cui sono passato
                    #chiamo in maniera ricorsiva CalcolaPercorso, se la condizione è verifacata return true
                    if(CalcolaPercorso(R,C,labirinto,labSoluzioni,movie_x,movie_y,new_x,new_y)):
                        return True
                    #se non verificata sono sicuro che per di li non posso passare pertanto porrò la nuova coordinata a 0
                    #backtraking
                    labSoluzioni[new_x][new_y]=0
        if(movie_x[i] == 1 or movie_x[i] == -1):
            
            new_y=c
            #ora li vado a controllare se questi due valori sono una possibile soluzione nel caso labirinto[new_x][new_y]
            if (CheckPasso(R,C,labirinto,labSoluzioni,new_x,new_y)):
                #se è verificato valido con uno la nuova pozione new_x, new_y
                labSoluzioni[new_x][new_y]=1
                #dopo aver salvato questa soluzione richiamo in maniera ricorsiva CalcolaPercorso, dandogli al posto di x ed y
                #x_new ed y_new che corrispondono alle nuove coordinate del punto in cui sono passato
                #chiamo in maniera ricorsiva CalcolaPercorso, se la condizione è verifacata return true
                if(CalcolaPercorso(R,C,labirinto,labSoluzioni,movie_x,movie_y,new_x,new_y)):
                    return True
                #se non verificata sono sicuro che per di li non posso passare pertanto porrò la nuova coordinata a 0
                #backtraking
                labSoluzioni[new_x][new_y]=0
    return False
                  

def DefinisciPercorso(labirinto,R,C):
        #creo labSoluzioni per andare a ricercare le possibili soluzioni
        labSoluzioni = [[0 for i in range(C)] for i in range(R)]
        
        ingresso = []
        uscita = []
        for i in range(R):
            if(labirinto[i][0] == 1):
                ingresso.append(i)
                labirinto[i][0] = 0
            if(labirinto[i][C-1] == 1):
                uscita.append(i)    
                labirinto[i][C-1] = 0
            
        for r in range(R):
            for c in range(1,C-1):
                if(labirinto[r][c] == 0):
                    
                    
                    if((r-1)>=0 and (r-1)<(R) and labirinto[r-1][c] == 1):
                        labirinto[r-1][c] = -1
                        
                    
                    if((r+1)>=0 and (r+1)<(R) and labirinto[r+1][c] == 1):   
                        labirinto[r+1][c] = -1
                        
                    
                    if((c-1)>0 and (c-1)<(C-1) and labirinto[r][c-1] == 1):
                        labirinto[r][c-1] = -1
                        
                        
                    if((c+1)>0 and (c+1)<(C-1) and labirinto[r][c+1] == 1):
                        labirinto[r][c+1] = -1
                        
        
        #definisco le matrice delle direzioni rispetto ad x ed y
        movie_x=[-1, 1, 0]
        movie_y = [0, -1, 1]
        somma = []
        for i in ingresso:
            labirinto[i][0] = 1
            labSoluzioni[i][0] = 1
            for u in uscita:
                labirinto[i][0] = 1
                labSoluzioni[i][0] = 1
                
                labirinto[u][C-1] = 1
                labSoluzioni[u][C-1] = 1
                
                StampaLabirinto("Stampa labSoluzioni: ",labSoluzioni,R,C)
                StampaLabirinto("Stampa LAB: ",labirinto,R,C)
            
                if(CalcolaPercorso(R,C,labirinto,labSoluzioni,movie_x,movie_y,i,0)):
                    
                    StampaLabirinto("Stampa Soluzione",labSoluzioni,R,C)
                    print("somma lab_SOL= "+str(sum(sum(labSoluzioni,[]))))
                    somma.append(sum(sum(labSoluzioni,[])))
                    print("somma= "+str(somma))
                
                    
                labSoluzioni = [[0 for i in range(C)] for i in range(R)]
                labirinto[u][C-1] = 0
                
                print("\n nessun percorso percorribile")
                
                
            
            labirinto[i][0] = 0

                
        return min(somma)
                
            
        
        
        
        






if __name__ == "__main__":
    #definisco il labirinto dove 1 rappresenta l'accesso e 0 rappresenta il muro
    labirinto = [[ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
           [ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 ],
           [ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 ],
           [ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ],
           [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 ],
           [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ],
           [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
           [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
           [ 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 ]]
    R = 9
    C = 10
    StampaLabirinto("Stampa labirinto: ",labirinto, R,C)
    print("\n")
    minimo = DefinisciPercorso(labirinto, R, C)
    
    print("\nil percorso minimo= "+str(minimo-2))