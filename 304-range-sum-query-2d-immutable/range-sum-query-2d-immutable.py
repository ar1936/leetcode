class NumMatrix:

    def __init__(self, mat: List[List[int]]):
        n = len(mat)
        m = len(mat[0])
        self.pre_sum = [[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                self.pre_sum[i][j] = mat[i][j]
                if i>0:
                    self.pre_sum[i][j] += self.pre_sum[i-1][j]
                if j>0:
                    self.pre_sum[i][j] += self.pre_sum[i][j-1]
                if i>0 and j>0:
                    self.pre_sum[i][j] -= self.pre_sum[i-1][j-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        total = self.pre_sum[row2][col2] 
        if row1>0:
            total -= self.pre_sum[row1-1][col2]
        if col1>0:
            total -= self.pre_sum[row2][col1-1]
        if row1>0 and col1>0:
            total += self.pre_sum[row1-1][col1-1]
        return total 


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)