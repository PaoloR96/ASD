#Input:
#N = 11 
#arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
#Output: 3 
#Explanation: 
#First jump from 1st element to 2nd 
#element with value 3. Now, from here 
#we jump to 5th element with value 9, 
#and from here we will jump to the last. 

#User function Template for python3

def CountJump(arr, n):
        #code here
        if n <= 1:
            return 0
        
        inizio = 0
        cont_jump = 0
        i = inizio
        
        while (i<n-1):
            
            if(arr[i] == 0):
                i = i + 1
                cont_jump = 0
            else:
                cont_jump = cont_jump + 1
                i = i+arr[i]
        
        if (cont_jump == 0):
            cont_jump = -1
            
        
        return cont_jump

    



if __name__ == '__main__':
    arr = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    cont=CountJump(arr,len(arr))
    print(cont)
        