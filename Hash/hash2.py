#Elemento più frequente in un array
#Input : arr[] = {1, 3, 2, 1, 4, 1}
#Output : 1
#Spiegazione: 1 appare tre volte nell'array che è la frequenza massima.

#Input: arr[] = {10, 20, 10, 20, 30, 20, 20}
#Output: 20
###############################################àà
def CercaElementoFreq(a,dim):
    hashmap={}
    #inserimento hash
    for i in range(dim):
        if a[i] in hashmap.keys():
            hashmap[a[i]]+=1
        else:
            hashmap[a[i]]=1
    max_freq=0
    res=-1
    for i in hashmap:
        if(max_freq<hashmap[i]):
            res=i
            max_freq=hashmap[i]
    return res
            
        
    



#################################################
# Driver Code
if __name__ == "__main__":
 
    arr = [ 40,50,30,40,50,30,30,40,40,40,40]
    dim = len(arr)
    print(CercaElementoFreq(arr,dim))