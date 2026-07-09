    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        n = len(arr)
    l = 1
    r = n - 2
    while l <= r:
        m = (l + r) // 2
        if arr[m-1] < arr[m] > arr[m+1]:
            return m
        elif arr[m-1] > arr[m]: 
            # arr[m-1] > arr[m] > arr[m+1] ==> search left, since we are in right region
            r = m - 1
        else: 
            # arr[m-1] < arr[m] < arr[m+1] ==> search right, since we are in left region
            l = m + 1 
        
    return -1