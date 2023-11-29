from random import randrange

#definisco la classe Nodo_albero
class TreapNode:
	
 	# ogni nodo avrà un valore con la relativa priorità
	def __init__(self, valore, sinistra=None, destra=None):
		self.valore = valore
		self.priorita = randrange(100)
		self.sinistra = sinistra
		self.destra = destra

# ruotaSinistra
# esegue l'operazione di rotazione a sinistra sul Treap a cui viene passata la radice del Treap come parametro
def ruotaSinistra(radice):
    
	# figlio destro della radice
	D = radice.destra
	# figlio di sinistra del figlio di destra della radice
	X = radice.destra.sinistra

	# ruota
	D.sinistra = radice
	radice.destra = X

	# definisco una nuova radice
	return D

# ruotaDestra
# esegue l'operazione di rotazione a destra sul Treap a cui viene passata la radice del Treap come parametro
def ruotaDestra(radice):

 	# figlio sinistro della radice
	S = radice.sinistra
	# figlio di destra del figlio di sinistra della radice
	Y = S.destra

	# ruota 
	S.destra = radice
	radice.sinistra = Y

	# definisco una nuova radice
	return S


# Funzione ricorisiva, in cui inserisco i vari nodi, in funzione della priorità all'interno  dell'albero
def InsNodo(radice, valore):

	# caso base
	if radice is None:
		return TreapNode(valore)

	# se il valore risulta minore del valore radice,effettuo l'insermento  a sinistra nel  sottoalbero;
	if valore < radice.valore:
		radice.sinistra = InsNodo(radice.sinistra, valore)

		# rotazione a destra se la proprietà di heap è violata
		if radice.sinistra and radice.sinistra.priorita > radice.priorita:
			radice = ruotaDestra(radice)
    # se il valore risulta maggiore del valore radice,effettuo l'insermento  a destra nel  sottoalbero;
	if valore > radice.valore:
		radice.destra = InsNodo(radice.destra, valore)

		# rotazione a sinistra se la proprietà di heap è violata
		if radice.destra and radice.destra.priorita > radice.priorita:
			radice = ruotaSinistra(radice)

	return radice


# Stampa dell' albero in modo da vedere visivamente la struttura di quest'ultimo
def printTreap(radice, space):

	height = 10
	if radice is None:
		return

 	# incremento della distanza tra i livelli
	space += height

	# stampa del primo figlio a destra
	printTreap(radice.destra, space)

 
	for i in range(height, space):
		print(' ', end='')

	# stampa radice
	print((radice.valore, radice.priorita))

	# stampa  del figlio di sinista
	printTreap(radice.sinistra, space)

#codice di test
def test(listaElementi,numtest):
        radice = None
        print(numtest +"\n")
        for valore in listaElementi:
            
          radice = InsNodo(radice, valore)
        print("Costruzione Albero , inerente al " + numtest + " :\n\n")
        printTreap(radice, 0)

# in generale avremo una complessità O(logn)
# la stampa dell'albero è impostata da sinistra verso destra

test([1,2,3,4,5,6,7,8,9,10],"test1")
test([1,2,3,4,5,6],"test2")
test([1,2],"test3")
test([11,2,44,55],"test4")