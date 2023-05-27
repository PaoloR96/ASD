#Print All Distinct Elements of a given integer array
def PrintElementi(a,dim):
    hash= {};
    s=[]
    #riempo hash
    for i in range(dim):
        if  a[i] not in hash.keys():
            hash[a[i]]=a[i]
            #print(hash[a[i]])
            s.append(a[i])
    return s        
            

# Driver Code
if __name__ == "__main__":
 
    arr = [ 40,50,30,40,50,30,30,40,40,40,40]
    dim = len(arr)
    print(PrintElementi(arr,dim))