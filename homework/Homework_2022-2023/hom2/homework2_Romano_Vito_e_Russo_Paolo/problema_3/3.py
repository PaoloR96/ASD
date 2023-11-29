#l'idea è quella di usare una matrice ausiliara S, contenente "gli indici" delle dimensioni delle sotto matrici contenenti tutti 0. Ovvero ogni elemento di esse lo
#considero come lo spigolo di basso a destra di una sottomatrice di 0 di dimensioni uguali proprio al valore dell'elemento di S 

def trovaSottoMatrice(M,R,C):

    S = [[0 for i in range(C)] for i in range(R)]
    
    # imposto la prima colonna e la prima riga di esse come l'opposto di quella della matrice di input
    for i in range(R):
        temp = []
        for j in range(C):
            if i == 0 or j == 0:
                if(M[i][j] == 0):
                    temp.append(1)
                else:
                    temp.append(0)
            else:
                temp.append(0)
        S.append(temp)

    # per gli altri elementi, effettuo il controllo degli elementi S[i][j-1], S[i-1][j], S[i-1][j-1], prendendone il minimo ed aggiungendo uno, in modo tale
    # da impostare in S[i][j] il valore della dimensione della  sottomatirce contenete tutti zero con spigolo inferiore destro nelle posizioni [i][j] 
    for i in range(1, R):
        for j in range(1, C):
            if (M[i][j] == 0):
                S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
            else:
                S[i][j] = 0

    # trovo la massima sottomatrice in S e salvo le posizioni (saranno le posizioni dello spigolo inferiore desatro della sottomatrice contente tutti 0)
    max_s = S[0][0]
    max_i = 0
    max_j = 0
    for i in range(R):
        for j in range(C):
            if (max_s < S[i][j]):
                max_s = S[i][j]
                max_i = i
                max_j = j
    
    #stampo la sottomatrice trovata
    print("la sottomatrice massima e': ")
    for i in range(max_i, max_i - max_s, -1):
        for j in range(max_j, max_j - max_s, -1):
            print(M[i][j], end=" ")
        print("")


# caso di tes
M = [[1,0,1,0,1,0,0],
      [1,0,0,0,1,0,0],
      [1,0,0,0,1,1,1],
      [1,0,0,0,1,1,1]]
R = 4
C = 7

trovaSottoMatrice(M,R,C)

