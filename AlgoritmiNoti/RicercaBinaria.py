
# Input: arr[] = {10, 20, 30, 40, 60, 110, 120, 130, 170}, x = 175
def RicercaBinaria(Arr, ind, DimmArr, x):
        while (ind<=DimmArr):

            mid = ind + (DimmArr - ind) // 2
            #considero tre casi
            if Arr[mid]==x :
                return mid;
            if Arr[mid]<x :
                ind=mid+1;
            else:
                DimmArr=mid-1;

        #se non è presente
        return -1;        
                
    




if __name__ == '__main__':

    # Driver Code
    Arr = [2, 3, 4, 10, 40]
    x = 10
 
    # Function call
    result = RicercaBinaria(Arr, 0, len(Arr)-1, x)
    if result != -1:
        print("Elemento  presente nella posizione % d" % result)
    else:
        print("Elemento non è presente")