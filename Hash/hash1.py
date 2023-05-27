#Operazione minima per rendere tutti gli elementi uguali nell'array
#######################################################
from collections import defaultdict
def MinOperetion(a,dim):
    hashmap={}
    hashmap = defaultdict(lambda:0)
    for i in range(dim):
        hashmap[a[i]]+=1;
    max=0
    for i in (hashmap):
        #print(hashmap[i])
        if max < hashmap[i]:
            max = hashmap[i]
    return dim - max







######################################################
# Driver Code
if __name__ == "__main__":
 
    arr = [1, 5, 2, 1, 3, 2, 1]
    dim = len(arr)
    print(MinOperetion(arr,dim))