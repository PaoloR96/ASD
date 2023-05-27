
#Problema 1.2
#Sia data una sequenza di n numeri interi, memorizzata in un vettore A. Si implementi un
#algoritmo che esegua in tempo O(nlogn) per determinare il numero di elementi minori uguali
#dell’elemento i-esimo, riportando il risultato corrispondente in un secondo vettore B (sempre
#di dimensione n) alla posizione i.
#Si alleghi al PDF un file editabile riportante l’implementazione in un linguaggio a scelta,
#corredato da almeno tre casi di test (dunque, una sequenza di numeri iteri in questo caso,
#con il corrispondente output atteso)


def countingSort(Arr):
    
    #calcolo min e max , abbimo un for con if , pertanto la complessità sarà O(n)
    max = min = 0
    size = len(Arr)
    for i in range(0, size):
        if(Arr[i] > max):
            max = Arr[i]
        elif(Arr[i] < min):
            min = Arr[i]

    range_of_elements = max - min + 1
    #inizializzo a 0 il vettore finale ed vettore dei count
    output = [0 for _ in range(size)]
    count = [0 for _ in range(range_of_elements)]

    for i in range(0, size):
        count[Arr[i] - min] += 1

    for i in range(1, max-min+1):
        count[i] += count[i - 1]

    for i in range(0, size):
        
        output[i] = count[Arr[i]-min]
       

    return output


# Driver program to test above function
A = [1,1,1,1]
B = countingSort(A)
print("A= " + str(A))
print("B= " + str(B))

A = [4,3,5,2,1,10,1,0,1]
B = countingSort(A)
print("A= " + str(A))
print("B= " + str(B))

A = [-1,-1,2,0,-4]
B = countingSort(A)
print("A= " + str(A))
print("B= " + str(B))