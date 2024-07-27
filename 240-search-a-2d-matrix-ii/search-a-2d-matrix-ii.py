class Solution:
    def searchMatrix(self, grid: List[List[int]], target: int) -> bool:
        n = len(grid)
        m = len(grid[0])
        row = n-1
        col = 0
        while row>=0 and col<m:
            if grid[row][col]<target:
                col+=1
            elif grid[row][col]>target:
                row-=1
            else:
                return True
        return False