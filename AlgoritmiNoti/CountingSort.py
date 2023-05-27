def CountSort(arr):
    
        max_element = int(max(arr))
        min_element = int(min(arr))
        rangeElem=max_element-min_element+1
        count_arr = [0 for _ in range(rangeElem)]
        arrOut = [0 for _ in range(len(arr))]
        
         # Memorizzo in cout_arr il conteggio relativo ad ogni elemento presente i arr
        for i in range(0, len(arr)):
            count_arr[arr[i]-min_element] =count_arr[arr[i]-min_element]+ 1

        for i in range(1, len(count_arr)):
            count_arr[i] =count_arr[i]+ count_arr[i-1]

        for i in range(len(arr)-1, -1, -1):
            arrOut [count_arr[arr[i] - min_element] - 1] = arr[i]
            count_arr[arr[i] - min_element] =count_arr[arr[i] - min_element]- 1
  
        # Copy the output array to arr, 
        
        for i in range(0, len(arr)):
            arr[i] = arrOut[i]
  
        return arr


def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print() 


if __name__ == '__main__':
    arr = [12, 2, 13, 5, 6, 7]
    print("Array da ordinare", end="\n")
    printList(arr)
   
    arr1=CountSort(arr)
    print("Array ordinato con CountingSort:", end="\n")
    printList(arr1)