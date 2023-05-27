
 #Per l'n-esimo elemento ci sono due scelte:
 #1) l'n-esimo elemento rimane single, si ricorre per f(n – 1)
 #2) l'n-esimo elemento si accoppia con un qualsiasi altro elemento restate: n – 1 elementi.
 #Otteniamo (n – 1) * f(n – 2) Quindi possiamo scrivere ricorsivamente f(n) come: f(n) = f(n – 1) + (n – 1) * f(n – 2)
 
 #trasformo semplicemente questo ragionamento in algoritmo
 
def contaModi(n):
 
    arr = [0 for i in range(n + 1)]
 
    # riempio arr in modalità bottom-up
    for i in range(n + 1):
 
        if(i <= 2):
            arr[i] = i
        else:
            arr[i] = arr[i - 1] + (i - 1) * arr[i - 2]
 
    return arr[n]
 
# casi di test
while True:
    print("Per uscire insersci 0")
    n = int(input("inserisci n: "))
    if(n==0):
        break
    print(contaModi(n))
    print('\n')