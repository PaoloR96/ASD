
def mergeSort(arr):
    cont=0
    if len(arr)>1:
        #vado a calcolare la meta della dim
        mid=len(arr)//2;
        #vado a suddividere arr in due sottoarray arr1 e arr2
        #arr1 va da [0_ _ mid]
        arr1=arr[:mid]
        #arr2 va da [mid_ _ n]
        arr2=arr[mid:]

        #vado ad iterere il ragionamento fatto per arr , sia per arr1, che arr2
        mergeSort(arr1)
        mergeSort(arr2)
        i = j = k = 0
        #vado a confrontare gli elementi di arr1 ed arr2 , ed in base al valore dell'if vado ad aggiungere in arr
        while i< len(arr1) and j< len(arr2):

            if arr1[i]<=arr2[j]:
                arr[k]=arr1[i]
                i=i+1
                #cont=cont+1
            else:
                 arr[k]=arr2[j]
                 j=j+1
                 
            k=k+1
        #Copio gli elementi rimanenti di arr1, in arr
      
        while i < len(arr1):
            arr[k] = arr1[i]
            i=i+ 1
            k =k+ 1

        #Copio gli elementi rimanenti di arr1, in arr
        
        while j < len(arr2):
            arr[k] = arr2[j]
            j=j+ 1
            k =k+ 1
    print(k) 

def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print()   
    

if __name__ == '__main__':
    arr = [2,8,5,4]
    print("Array da ordinare", end="\n")
   # printList(arr)
    
    mergeSort(arr)
    
    #print("Array ordinato con MergeSort:", end="\n")
    #printList(arr)