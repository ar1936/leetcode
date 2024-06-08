class Solution:
    def spiralOrder(self, mat: List[List[int]]) -> List[int]:
        n = len(mat)
        m = len(mat[0])
        left = 0
        right = m -1
        top = 0
        bottom = n - 1
        ans = []
        while left<=right and top<=bottom:
            for j in range(left,right+1):
                ans.append(mat[top][j])
            top+=1

            for i in range(top,bottom+1):
                ans.append(mat[i][right])
            right-=1

            if top<=bottom:
                for j in range(right,left-1,-1):
                    ans.append(mat[bottom][j])
                bottom -= 1

            if left<=right:
                for i in range(bottom,top-1,-1):
                    ans.append(mat[i][left])
                left+=1
        return ans