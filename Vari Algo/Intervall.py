def printList(arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
            print()

def nextLargerElement(arr,n):
    s = []
    for i in range(n):
        while s and s[-1].get("value") < arr[i]:
            d = s.pop()
            arr[d.get("ind")] = arr[i]
            s.append({"value": arr[i], "ind": i})
        while s:
            d = s.pop()
            arr[d.get("ind")] = -1
    return arr

if __name__ == '__main__':
    arr = [1,3,2,4]
    dim=len(arr)
    print(nextLargerElement(arr,dim))