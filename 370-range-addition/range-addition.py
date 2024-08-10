class Solution:
    def getModifiedArray(self, n: int, updates: List[List[int]]) -> List[int]:
        arr = [0]*(n+1) 
        for (i,j, v) in updates:
            arr[i]+=v
            arr[j+1]-=v
        sum = 0
        for i in range(n):
            sum+=arr[i]
            arr[i] = sum
        return arr[:-1]