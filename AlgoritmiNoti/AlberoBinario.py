
# Python program to insert element in binary tree
class newNode():
 
    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None
         
""" Stampa Albero Binario , ordinato"""
def PrintTree(temp):
 
    if (not temp):
        return
 
    PrintTree(temp.left)
    print(temp.key,end = " ")
    PrintTree(temp.right)

 
"""function to insert element in binary tree """
def InsNode(temp,key):
 
    if not temp:
        root = newNode(key)
        return
    listaNodi = []
    listaNodi.append(temp)
 
    while (len(listaNodi)):
        temp = listaNodi[0]
        listaNodi.pop(0)
 
        if (not temp.left):
            temp.left = newNode(key)
            break
        else:
            listaNodi.append(temp.left)
 
        if (not temp.right):
            temp.right = newNode(key)
            break
        else:
            listaNodi.append(temp.right)
     
# Driver code
if __name__ == '__main__':
    root = newNode(10)
    root.left = newNode(11)
    root.left.left = newNode(7)
    root.right = newNode(9)
    root.right.left = newNode(15)
    root.right.right = newNode(8)
 
    print("Stampa Albero Binario:", end = " ")
    PrintTree(root)
    #inserimento nuovo nodo
    key = 12
    InsNode(root, key)

    key = 22
    InsNode(root, key)
    key = 50
    InsNode(root, key)
   
    print()
    print("Stampa Albero Binario, dopo inserimento:", end = " ")
    PrintTree(root)
 