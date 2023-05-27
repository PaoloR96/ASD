def InsertSort(arr):

     for i in range(1, len(arr)):
        #prendo l'elemento da confrotare
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j =j- 1
        arr[j + 1] = key
    
def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print()   
    

if __name__ == '__main__':
    arr = [12, 2, 13, 5, 6, 7]
    print("Array da ordinare", end="\n")
    printList(arr)
   
    InsertSort(arr)
    print("Array ordinato con InsertSort:", end="\n")
    printList(arr)