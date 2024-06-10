class Solution:
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:
        def binary_search(arr):
            low = 0 
            high = len(arr) -1 
            while low<=high:
                mid = low+(high-low)//2
                if arr[mid] == target:
                    return True
                elif arr[mid]>target:
                    high = mid -1
                else:
                    low = mid +1
            return False
        
        for m in mat:
            if m[0]<=target and target<=m[-1]:
                return binary_search(m)
        return False