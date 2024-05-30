from typing import List

class Solution:
    def __init__(self):
        self.isVisited = [[False] * 51 for _ in range(51)]
        self.result = []
        self.ROW = 0
        self.COL = 0
        self.COLOR = 0

    def isValid(self, grid: List[List[int]], i: int, j: int) -> bool:
        return (0 <= i < self.ROW and 0 <= j < self.COL and 
                grid[i][j] == self.COLOR and not self.isVisited[i][j])
    
    def isBorder(self, grid: List[List[int]], i: int, j: int) -> bool:
        if i == 0 or i == self.ROW - 1 or j == 0 or j == self.COL - 1:
            return True
        if (grid[i][j + 1] != self.COLOR or grid[i][j - 1] != self.COLOR or 
            grid[i + 1][j] != self.COLOR or grid[i - 1][j] != self.COLOR):
            return True
        return False

    def DFS(self, grid: List[List[int]], i: int, j: int, color: int):
        self.isVisited[i][j] = True
        if self.isBorder(grid, i, j):
            self.result[i][j] = color
        else:
            self.result[i][j] = self.COLOR
        if self.isValid(grid, i, j + 1):
            self.DFS(grid, i, j + 1, color)
        if self.isValid(grid, i, j - 1):
            self.DFS(grid, i, j - 1, color)
        if self.isValid(grid, i + 1, j):
            self.DFS(grid, i + 1, j, color)
        if self.isValid(grid, i - 1, j):
            self.DFS(grid, i - 1, j, color)

    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        self.ROW = len(grid)
        self.COL = len(grid[0])
        self.COLOR = grid[r0][c0]
        self.result = [row[:] for row in grid]  # Make a copy of the grid
        self.isVisited = [[False] * self.COL for _ in range(self.ROW)]  # Reset visited array
        
        self.DFS(grid, r0, c0, color)
        
        return self.result
