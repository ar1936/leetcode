from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        
        n, m = len(heights), len(heights[0])
        
        pacific_reachable = set()
        atlantic_reachable = set()
        
        def dfs(x, y, reachable_set):
            reachable_set.add((x, y))
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in reachable_set and heights[nx][ny] >= heights[x][y]:
                    dfs(nx, ny, reachable_set)
        
        for i in range(n):
            dfs(i, 0, pacific_reachable)
            dfs(i, m - 1, atlantic_reachable)
        
        for j in range(m):
            dfs(0, j, pacific_reachable)
            dfs(n - 1, j, atlantic_reachable)
        
        return list(pacific_reachable & atlantic_reachable)
