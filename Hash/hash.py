#nione e Intersezione di due elenchi collegati
class linkedList:
    def __init__(self):
        self.head = None
        self.tail = None
  
    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next
  
  
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
  

  
  
def Intersezione(head1, head2):
   
    hashmap = {}
  

    while(head1 != None):
        data = head1.data
        if(data not in hashmap.keys()):
            hashmap[data] = 1
        head1 = head1.next
  

    ans = linkedList()
    while(head2 != None):
        data = head2.data
        if(data in hashmap.keys()):
            ans.insert(data)
        head2 = head2.next
    return ans.head
  
  
  
def Unione(head1, head2):
    # creazione map
    hashmap = {}
  
    # attraversamento lista1
    while(head1 != None):
        data = head1.data
        if(data not in hashmap.keys()):
            hashmap[data] = 1
        head1 = head1.next
    # attraversamento lista2
    while(head2 != None):
        data = head2.data
        if(data not in hashmap.keys()):
            hashmap[data] = 1
        head2 = head2.next
  
   
    newList = linkedList()
  
    
    for key, value in hashmap.items():
        newList.insert(key)
  
    return newList.head
  
  
def StampaLista(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()
  
  
if __name__ == '__main__':
  
    # lista1
    ll1 = linkedList()
    ll1.insert(1)
    ll1.insert(2)
    ll1.insert(3)
    ll1.insert(4)
    ll1.insert(5)
  
    # lista2
    ll2 = linkedList()
    ll2.insert(1)
    ll2.insert(3)
    ll2.insert(5)
    ll2.insert(6)
  
    print("Lista1 ")
    StampaLista(ll1.head)
  
    print("Lista2 ")
    StampaLista(ll2.head)
  
    print("Intersezione")
    StampaLista(Intersezione(ll1.head, ll2.head))
  
    print("Unione ")
    StampaLista(Unione(ll1.head, ll2.head))