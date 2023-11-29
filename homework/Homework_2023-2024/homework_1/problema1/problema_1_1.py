def mergeSort(arr, n):
    #Utilizzo un arrey temporanio per conservare gli array nella funzione di merge
    
    temp_arr = [0] * n
    return _mergeSort(arr, temp_arr, 0, n-1)
 
def _mergeSort(arr, temp_arr, i, j):
 
    
    #variabile per il conteggio delle inversioni
    inversioni = 0
 
    # We will make a recursive call if and only if
    # we have more than one elements
    # Chiamata recursiva <=> il numero di elementi che abbiamo è > 1
    
    if i < j:
 
        
        # calcolo med per la vivisione dell'arry in due sotto_arry
        med = (i + j)//2
 
        
        #conto le inversioni nell'array i
        inversioni += _mergeSort(arr, temp_arr,
                                i, med)
 
        
        #conto le inversioni nell'array j
        inversioni += _mergeSort(arr, temp_arr,
                                med + 1, j)
 
        
        #faccio il merge degli array
        inversioni += merge(arr, temp_arr, i, med, j)
    return inversioni
 
 
 
def merge(arr, temp_arr, sinistra, mid, destra):
    i = sinistra     # Idirizzo di partenza del sotto_array di sinistra
    j = mid + 1      # Indirizzo di partenza del sotto_array di sinistra
    k = sinistra     # Indirizzo di partenza del nuovo array merge
    inversioni = 0
 
 
    while i <= mid and j <= destra:
 
        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            k += 1
            i += 1
        else:
            
            temp_arr[k] = arr[j]
            inversioni += (mid-i + 1)
            k += 1
            j += 1
 
    
    # metto i restati elementi del sotto_array di sinistra in un array temporaneo
    while i <= mid:
        temp_arr[k] = arr[i]
        k += 1
        i += 1

    # metto i restati elementi del sotto_array di destra in un array temporaneo
    while j <= destra:
        temp_arr[k] = arr[j]
        k += 1
        j += 1
 
    # Metto il sottoarray riordinato nell'array originale
    for loop_var in range(sinistra, destra + 1):
        arr[loop_var] = temp_arr[loop_var]
 
    return inversioni
 
 
# Driver Code
""" uscita = True
vett = []

while uscita:
    n_vett = int(input("Inserisci la lunghezza del vettore da riordinare: "))
    vett.append(n_vett)
    
    if (n_vett > 0):
        for i in range(n_vett):
            vett.append(int(input("inserisci cifra "+ str(i+1) +": ")))
    else:
        uscita = False """
        
vett = [5,9,1,0,5,4,3,1,2,3,5,4,9,7,5,1,3,3,2,1,7,1,5,4,8,6,2,7,0]
            

    
usicta_2 = True
i = 0
j = 0
n_arr_temp = 0
arr= []

while usicta_2:
    n_arr = vett[i]
    n_arr_temp = vett[i] + n_arr_temp +1
    
    
    
    
    if (n_arr > 0):
        for j in range(i+1,n_arr_temp):
            arr.append(vett[j])
            
        i = j
        
        risultato = mergeSort(arr, n_arr)
        print("Il numero di inversioni e':", risultato)
        
        arr.clear()
    else:
        usicta_2 = False
        
    i += 1
    
    
# complessità O(n log n) perchè effettua un merge sort
#ho presentato anche una modalità di input dinamica