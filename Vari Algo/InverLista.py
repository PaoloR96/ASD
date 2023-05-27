#Problema 1.1
#Sia data una lista di 2n nomi memorizzati in una Linked List. Si implementi un algoritmo con
#complessità O(n) che modifichi la lista in modo tale da invertire l’ordine degli elementi della
#seconda metà della lista (dunque, in modo tal che l’(n+1)-esimo elemento diventi l’ultimo
#elemento (posizione 2n), l’’(n+2)-esimo diventi il penultimo e così via, l’ultimo elemento
#diventi l’(n+1)-esimo. L’algoritmo non deve creare nuovi nodi nella lista né istanziare nuove
#strutture dati.
#
#




class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList:

   # Function to initialize head
    def __init__(self):
        self.head = None
        self.dim=0
 
    # Function to reverse the linked list
    def reverse(self) :
              
        prev = None
        current = self.head
        for i in range (int(self.dim/2)-1):
            current =current.next
        #salvo il nodo corrente su un nodo d'appoggio chiamato pivot
        pivot=current 
        #current punto al valore n+1
        current=current.next
        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        #aggiorno il nodo pivot al precedente
        pivot.next = prev
 
    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
        self.dim=self.dim+1
 
    # Utility function to print the linked LinkedList
    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data);
            temp = temp.next
       # print("\nla dim della lista e' "+str(self.dim));
 
# Driver code
def test(listaElementi):
        llist = LinkedList()
        
        for listaElem in listaElementi:
            llist.push(listaElem)
 
        print ("\nLista Generata:")
        llist.printList()
        llist.reverse()
        print ("\nLista Modificata:")
        llist.printList()

test([1,2,3,4,5,6,7,8,9,10])
test([1,2,3,4,5,6])
test([1,2])

