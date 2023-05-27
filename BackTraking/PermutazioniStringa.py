def Permutazione(a, indice, dim):
    if indice==dim:
        print (''.join(a))
    else:
        for i in range(indice,dim):
            a[indice], a[i] = a[i], a[indice]
            Permutazione(a, indice+1, dim)
            a[indice], a[i] = a[i], a[indice] # backtrack
 
# Driver program to test the above function
stringa = "ABCD"
dim = len(stringa)
a = list(stringa)
Permutazione(a, 0, dim)
    