#Input: array = {1, 2, 3}
#Output: // this space denotes null element. 
#       1
#       1 2
#       1 2 3
#       1 3
#       2
#       2 3
#       3
global risultato

def GeneraSequenza(array,tmp,indice):
    print(*tmp)
    for i in range(indice,len(array)):
        tmp.append(array[i])
        GeneraSequenza(array,tmp,i+1)
        tmp.pop(-1)    
    return
def TrovaSequenza(array):
    tmp=[]

    GeneraSequenza(array,tmp,0)
########################################
if __name__ == "__main__":
    array = [1, 2, 3]
    TrovaSequenza(array)