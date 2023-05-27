def kLargest(self,arr, n, k):
		max_element = int(max(arr))
        min_element = int(min(arr))
        rangeElem=max_element-min_element+1
        count_arr = [0 for _ in range(rangeElem)]
        arrOut = [0 for _ in range(len(arr))]
        
         # Memorizzo in cout_arr il conteggio relativo ad ogni elemento presente i arr
        for i in range(0, len(arr)):
            count_arr[arr[i]-min_element] =count_arr[arr[i]-min_element]+ 1

        for i in range(1, len(count_arr)):
            count_arr[i] =count_arr[i]+ count_arr[i-1]

        for i in range(len(arr)-1, -1, -1):
            arrOut [count_arr[arr[i] - min_element] - 1] = arr[i]
            count_arr[arr[i] - min_element] =count_arr[arr[i] - min_element]- 1
  
        # Copy the output array to arr, 
        
        for i in range(0, len(arr)):
            if i<k:
                arr[i] = arrOut[n-1-i]
        return arr[:k]