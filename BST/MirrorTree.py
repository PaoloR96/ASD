#Mirror Tree
class Node:
    #costruttore nodo
    def __init__(self, valore, sinistra=None, destra=None):
        self.valore=valore
        self.right=destra
        self.left=sinistra

#funzione inserimento albero
def InsNodo(radice, valore):

    if radice is None:
        return Node(valore)
    if valore < radice.valore:
        radice.left = InsNodo(radice.left, valore)
    if valore > radice.valore:
        radice.right = InsNodo(radice.right, valore)
    return radice

#mirror 

def Mirror(radice):
    if radice is None:
        return
    temp = radice
    Mirror(radice.right)
    Mirror(radice.left)
    #scambio
    temp=radice.left
    radice.left=radice.right
    radice.right=temp
    


# Stampa albero
def PrintTree(radice):
    if radice is None:
        return 
    PrintTree(radice.right)
    print(radice.valore)
    PrintTree(radice.left)        

#######################################################################################
# Driver Code
if __name__ == '__main__':
    listaElem=[20,8,4,12,10,14,22]
    radice = None
    for valore in listaElem:
        radice=InsNodo(radice, valore)
    print("Albero BST:")
    PrintTree(radice)
    print("Albero BST Mirror:")
    Mirror(radice)
    PrintTree(radice)
    #quanti elementi vado a considerare
    
