class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def b_s(arr,target):
            l = 0
            r = len(arr)-1
            while l<=r:
                mid = l+(r-l)//2
                if arr[mid] == target:
                    return True
                elif arr[mid]<target:
                    l = mid + 1
                else:
                    r = mid - 1 
            return False
        for mat in matrix:
            if mat[0]<=target<=mat[-1]:
                return b_s(mat,target)
        return False