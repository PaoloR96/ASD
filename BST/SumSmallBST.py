#Somma di k elementi più piccoli in BST
################################################
class Node:
#costruttore nodo
    def __init__(self, valore, sinistra=None, destra=None,somma=0,cont=0):
        self.valore=valore
        self.right=destra
        self.left=sinistra
        self.Somma=somma
        self.Cont=cont

#funzione inserimento albero
def InsNodo(radice, valore):

    # caso base
    if radice is None:
        return Node(valore)

    # se il valore risulta minore del valore radice,effettuo l'insermento  a sinistra del  sottoalbero;
    if valore < radice.valore:
        
        radice.Cont+=1
        radice.Somma+=valore
        radice.left = InsNodo(radice.left, valore)

    # se il valore risulta maggiore del valore radice,effettuo l'insermento  a destra del  sottoalbero;
    if valore > radice.valore:
        radice.right = InsNodo(radice.right, valore)
        

    return radice

# Stampa albero

def PrintTree(radice):
    if radice is None:
        return 
    PrintTree(radice.right)
    print(radice.valore)
    PrintTree(radice.left)
########################################################################################
def SumSmallElement(radice, k):
    somma= [0]
    CalcolaSomma(radice,k,somma)
    return somma[0]


def CalcolaSomma(radice,k,tmp_somma):
    if radice is None:
        return
    if (radice.Cont + 1) == k:
        tmp_somma[0] += radice.valore + radice.Somma
        return
    
    if k > radice.Cont:
        tmp_somma[0] += radice.valore + radice.Somma
        #decremento k
        k = k -( radice.Cont + 1)
        CalcolaSomma(radice.right,k,tmp_somma)
    else:
        CalcolaSomma(radice.left,k,tmp_somma)
        
    
    




    
#######################################################################################
# Driver Code
if __name__ == '__main__':
    listaElem=[20,8,4,12,10,14,22]
    radice = None
    for valore in listaElem:
        radice=InsNodo(radice, valore)
    #PrintTree(radice)
    #quanti elementi vado a considerare
    k = 3
    print(SumSmallElement(radice, k))


