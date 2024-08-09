import heapq
from collections import deque

class Pair:
    def __init__(self, x, y, d):
        self.x = x
        self.y = y
        self.d = d
        
    def __lt__(self, other):
        return self.d > other.d  # Max-heap behavior by reversing comparison

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        arr = [[0] * m for _ in range(n)]
        self.bfs(grid, arr)  # Calculate the Manhattan distance
        
        if arr[0][0] == 0 or arr[n-1][m-1] == 0:
            return 0
        
        visited = [[False] * m for _ in range(n)]
        pq = []
        heapq.heappush(pq, Pair(0, 0, arr[0][0]))
        visited[0][0] = True

        delta = [0, -1, 0, 1, 0]
        while pq:
            curr = heapq.heappop(pq)
            row, col, dis = curr.x, curr.y, curr.d
            if row == n-1 and col == m-1:
                return dis  # Max-heap stores max on top, so the first time we visit the last cell, return the value
            
            for i in range(4):
                r = row + delta[i]
                c = col + delta[i+1]
                if 0 <= r < n and 0 <= c < m and not visited[r][c]:
                    visited[r][c] = True
                    heapq.heappush(pq, Pair(r, c, min(dis, arr[r][c])))
        
        return 0

    def bfs(self, grid: List[List[int]], arr: List[List[int]]):
        n = len(grid)
        m = len(grid[0])
        que = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    que.append(Pair(i, j, 0))
        
        delta = [0, -1, 0, 1, 0]
        while que:
            curr = que.popleft()
            row, col, dis = curr.x, curr.y, curr.d
            
            for i in range(4):
                r = row + delta[i]
                c = col + delta[i+1]
                d = dis + 1
                if 0 <= r < n and 0 <= c < m and arr[r][c] == 0 and grid[r][c] != 1:
                    arr[r][c] = d
                    que.append(Pair(r, c, d))
