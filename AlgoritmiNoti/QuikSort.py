def partition(arr, low, high):
      
    # imposto il pivot prendendo l'ultimo elemeto 
    pivot = arr[high]
  
    # Pointer per l'elemento  maggiore
    i = low - 1
  
    
    # comparo ogni elemento con il pivot
    for j in range(low, high):
        if arr[j] <= pivot:
            # se l'elemeto è piu piccolo del pivot swap
            i = i + 1
            (arr[i], arr[j]) = (arr[j], arr[i])
  
    # Swap gli elementi 
    (arr[i + 1], arr[high]) = (arr[high], arr[i + 1])

    #ritorna la posizione dove è avvenuta la partizione
    return i + 1
  
def QuickSort(arr, low, high):
    if low < high:
  
        # Find pivot element in fuzione del quale vado ad effettuare il partizionamento
        pi = partition(arr, low, high)
  
        # chiamata ricorsiva alla sinistra del pivot
        QuickSort(arr, low, pi - 1)
  
        # chiamata ricorsiva alla destra del pivot
        QuickSort(arr, pi + 1, high)


def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print() 


if __name__ == '__main__':
    arr = [12, 2, 13, 5, 6, 7]
    print("Array da ordinare", end="\n")
    printList(arr)
   
    QuickSort(arr,0, len(arr) - 1)
    print("Array ordinato con QuikSort:", end="\n")
    printList(arr)