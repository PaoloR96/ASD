def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print() 


if __name__ == '__main__':
    arr = [12, 2, 13, 5, 6, 7]
    print("Array da ordinare", end="\n")
    printList(arr)
   
    RadixSort(arr)
    print("Array ordinato con RadixSort:", end="\n")
    printList(arr1)