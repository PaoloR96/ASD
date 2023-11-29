def Prefisso_Comune(str1, str2):

    Com = ""
    n1, n2 = len(str1), len(str2)
    i, j = 0, 0

 

    while i <= n1 - 1 and j <= n2 - 1:

        if str1[i] != str2[j]:
            break

        Com += str1[i]
        i, j = i + 1, j + 1
        
    return Com

 

 

def Prefisso_Più_Lungo(Stringhe, low, high):

    if low == high:
        return Stringhe[low]

    if high > low:

        mid = low + (high - low) // 2
        str1 = Prefisso_Più_Lungo(Stringhe, low, mid)
        str2 = Prefisso_Più_Lungo(Stringhe, mid + 1, high)

        return Prefisso_Comune(str1, str2)

 
if __name__ == "__main__":

    Test_case1 = ["apple", "ape", "april", "applied"]
    n = len(Test_case1)
    Risultato = Prefisso_Più_Lungo(Test_case1, 0, n - 1)

    if len(Risultato):
        print("Il prefisso comune più lungo è", Risultato)

    else:
        print("Nessun Prefisso comune")

    Test_case2 = ["luigi", "ugo", "rebecca", "chiara", "cristina", "cristian", "pasquale"]
    n = len(Test_case2)
    Risultato = Prefisso_Più_Lungo(Test_case2, 0, n - 1)

    if len(Risultato):
        print("Il prefisso comune più lungo è", Risultato)

    else:
        print("Nessun Prefisso comune")

    Test_case3 = ["nessun", "prefisso", "lungo", "comune"]
    n = len(Test_case3)
    Risultato = Prefisso_Più_Lungo(Test_case3, 0, n - 1)

    if len(Risultato):
        print("Il prefisso comune più lungo è", Risultato)
    else:
        print("Nessun Prefisso comune")

    Test_case4 = ["uguali", "uguali", "uguali", "uguali"]
    n = len(Test_case4)
    Risultato = Prefisso_Più_Lungo(Test_case4, 0, n - 1)

    if len(Risultato):
        print("Il prefisso comune più lungo è", Risultato)
        
    else:
        print("Nessun Prefisso comune")  
        
#complessità O(n*m)
# per quanto riguarda l'input non abbiamo ben capito il significato del numero 1 nel sample input. Duqnue abbiamo optato per dividere i vari casi di test 
# in modo statico.