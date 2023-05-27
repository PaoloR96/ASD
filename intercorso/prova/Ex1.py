#Complessità --->O(nlogn)
def CheckOccorrenza(arr, l, r, k):
    
    #controllo se sono arrivato a dividere fino a un solo elemento
    if ((l > r) or (l == r and arr[l] != k)):
        return 0

    #se sono a un solo elemento ed è k allora ritorno 1
    if (l == r and arr[l] == k):
        return 1
    #divido in due parti
    return CheckOccorrenza(arr, l, (l + r) // 2, k) + CheckOccorrenza(arr, 1 + (l + r) // 2, r, k)
# main
if __name__ == "__main__":

    #casi di test
    Ntest = int(input('casi test: '))

    arr = []
    for i in range(Ntest):

        k = int(input('k: '))
        dim_arr = int(input('dim_arr: '))
        input_arr = input('')
        arr = []
        for elem in input_arr.split(' '):
            arr.append(int(elem))

        arr.append(CheckOccorrenza(arr, 0, dim_arr - 1, k))
    print("Stampa numero occorenze")
    for elem in arr:
        print(elem)





       
     