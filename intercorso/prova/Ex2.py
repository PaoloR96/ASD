# Complessità--->O(2^k-1-1)
import math

#vettore per memorizzare gli N primi
set = []
prime = []

# controllo se x è primo
def IsPrimo(x) :

	# radice di x
	sqroot = int(math.sqrt(x))
	flag = True

	# se ho uno
	if (x == 1) :
		return False

	# se qualche fattoriale è stato trovato ritorna falso
	for i in range(2, sqroot + 1) :
		if (x % i == 0) :
			return False

	# nessub fattoriale trovato
	return True

# Stampa  N primi la cui somma è pari ad S
def PrintNumeri() :

	global set, prime
	length = len(set)
	for i in range(0, length) :
		print (set[i], end = " ")
	print ()



# Valuto  tutti i  possibli N primi la cui  somma  è pari ad S
def primiSum(totale, N, S, indice) :
	
	global set, prime
	
	if (totale == S and
		len(set) == N) :
	
		# Stamoa  N primi
		PrintNumeri()
    
		return

    #se il totale della somma è maggiore di S o la lunghezza
	if (totale > S or
		indice == len(prime)) :
		return

	# agg prime[index]  al vettore set 
	set.append(prime[indice])
	# includo  (index)th
	# prime to total
	primiSum(totale + prime[indice],
				N, S, indice + 1)

	#rimuovo gli elementi dal vettore
	set.pop()

	
	primiSum(totale, N,
			S, indice + 1)

# funzione per generare i numeri primi
def GeneraPrimi(N, S, P) :

	global set, prime
	
	# tutti i primi  prima di S
	for i in range(P + 1,
				S + 1) :
	
		#se è primo agg al vettore prime
		if (IsPrimo(i)) :
			prime.append(i)
	
	#se il numero primi sono meno di N
	if (len(prime) < N) :
		return
	primiSum(0, N, S, 0)

if __name__ == "__main__":
    Ntest = int(input('casi test: '))
    for i in range(Ntest):
        print("Ins Seq:")
        S = int(input('S: '))
        N = int(input('N: '))
        P = int(input('P: '))
        print("CasoTest"+str(i))
        i=int(i)
        GeneraPrimi(N, S, P)
        set.clear()
        prime.clear()

