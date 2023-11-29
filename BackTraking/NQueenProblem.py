N = 4
Queen = "Q"


def StampaScacchiera(Val, labirinto):
    print()
    print(Val)
    for i in range(N):
        for j in range(N):
            print(labirinto[i][j], end=' ')
        print()


def IsValida(scacchiera, riga, colonna):
    # controllo le varie posizioni
    # 1)controllo la riga sul lato di sinistra
    # fisso la riga e mi sposo colonna per colonna se trovo la posizione occupata esco dalla funzione
    for i in range(colonna):
        if scacchiera[riga][i] == Queen:
            return False;
    # 2)controllo la diagonale  superiore sul lato sinistra
    for i, j in zip(range(riga, -1, -1), range(colonna, -1, -1)):
        if scacchiera[i][j] == Queen:
            return False

    # 3) controllo la diagonale  inferiore sul lato sinistra
    for i, j in zip(range(riga, N, 1), range(colonna, -1, -1)):
        if scacchiera[i][j] == Queen:
            return False
    # nel caso le condizioni di controllo sono state verificate non andando in false vuol dire che
    # la posizione scacchiera[riga][colonna] è libera e posso sovrascriverla
    return True;


def PosizionaQueen(scacchiera, colonna):
    # se sono arrivato alla fine ritorna True
    if colonna >= N:
        return True;
    for i in range(N):
        if IsValida(scacchiera, i, colonna):

            # se la condizione è valida allora posso sovrascrivere
            scacchiera[i][colonna] = Queen
            # effettuo l'analisi della posizione alla colonna successiva
            if (PosizionaQueen(scacchiera, colonna + 1) == True):
                return True;
        # backtraking
        scacchiera[i][colonna] = 0
    return False;


def CalocolaNQueen(scacchiera):
    if (PosizionaQueen(scacchiera, 0) == False):
        print("La soluzione non esiste!!")
        return False
    StampaScacchiera("Stampa Soluzione:", scacchiera)
    return True


# N Queen Problem
if __name__ == "__main__":
    # definisco la scacchiera e poniamo a 0 tutti gli elementi a 0
    scacchiera = [[0 for i in range(N)] for i in range(N)]
    print("\n")
    StampaScacchiera("Stampa iniziale scacchiera:", scacchiera)
    CalocolaNQueen(scacchiera)
