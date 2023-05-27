from random import randrange

class TreapNode:
	
	def __init__(self, valore, sinistra=None, destra=None):
		self.valore = valore
		self.priorita = randrange(100)
		self.sinistra = sinistra
		self.destra = destra


def ruotaSinistra(radice):

	D = radice.destra
	X = radice.destra.sinistra

	# ruota
	D.sinistra = radice
	radice.destra = X

	# # definisco una nuova radice
	return D


def ruotaDestra(radice):

	S = radice.sinistra
	Y = radice.sinistra.destra

	# rotazione
	S.destra = radice
	radice.sinistra = Y

	# definisco una nuova radice
	return S


# Funzione ricorisiva, in cui inserisco i vari nodi, in funzione della priorità all'interno  dell'albero
def InsNodo(radice, valore):

	# caso base
	if radice is None:
		return TreapNode(valore)

	# se il valore risulta minore del valore radice,effettuo l'insermento  a sinistra del  sottoalbero;
	if valore < radice.valore:
		radice.sinistra = InsNodo(radice.sinistra, valore)

		# rotazione a destra se la propertà di heap è violata
		if radice.sinistra and radice.sinistra.priorita > radice.priorita:
			radice = ruotaDestra(radice)
    # se il valore risulta maggiore del valore radice,effettuo l'insermento  a destra del  sottoalbero;
	if valore > radice.valore:
		radice.destra = InsNodo(radice.destra, valore)

		# rotazione a sinistra se la propertà di heap è violata
		if radice.destra and radice.destra.priorita > radice.priorita:
			radice = ruotaSinistra(radice)

	return radice


# Stampa albero
def printTreap(radice, space):

	height = 10
	if radice is None:
		return

	# increase distance between levels
	space += height

	# stampa del primo figlio a destra
	printTreap(radice.destra, space)

	# stampa del nodo corrente  
	for i in range(height, space):
		print(' ', end='')

	print((radice.valore, radice.priorita))

	# stampa  del figlio di sinista
	printTreap(radice.sinistra, space)


def test(listaElementi,numtest):
        radice = None
        print(numtest +"\n")
        for valore in listaElementi:
            
          radice = InsNodo(radice, valore)
        print("Costruzione Albero , inerente al " + numtest + " :\n\n")
        printTreap(radice, 0)


test([1,2,3,4,5,6,7,8,9,10],"test1")
test([1,2,3,4,5,6],"test2")
test([1,2],"test3")
test([11,2,44,55],"test4")