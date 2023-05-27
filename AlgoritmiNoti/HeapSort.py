
def heapify(arr, N, i):
    #imposto largest come radice
    root = i
    #defisco i figli left e right
    left=2*i+1
    right=2*i
    #vedo se il figlio sinistro della radice[ root] esiste ed è più grande della radice
    if left  < N and arr[ root]<arr[left]:
         root=left
    #vedo se il figlio di desta della radice[ root] esiste ed è più grande della radice
    if right  < N and arr[root]<arr[right]:
         root=right
    #cambio radice
    if  root != i:
            #scambio
           arr[i], arr[ root] = arr[ root], arr[i]
           heapify(arr, N,  root)




def HeapSort(arr):
    N=len(arr)
    #costruisco maxheap
    for i in range(N//2 - 1, -1, -1):
            heapify(arr, N, i)
    # estrazione elemento per elemento
    for i in range(N-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)








def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print() 


if __name__ == '__main__':
    arr = [12, 2, 13, 5, 6, 7]
    print("Array da ordinare", end="\n")
    printList(arr)
   
    HeapSort(arr)
    print("Array ordinato con HeapSort:", end="\n")
    printList(arr)