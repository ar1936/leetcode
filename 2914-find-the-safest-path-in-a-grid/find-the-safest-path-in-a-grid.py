class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        n = len(grid) 
        m = len(grid[0])
        dis = [[float('inf')]*m for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    q.append((0, i, j))
                    dis[i][j] = 0
        while q:
            d, x, y = q.popleft()
            for k in range(4):
                r, c = x + dx[k], y + dy[k]
                if 0<=r<n and 0<=c<m:
                    if dis[r][c] > dis[x][y]+1:
                        dis[r][c] = dis[x][y] + 1
                        q.append((dis[r][c], r, c))
        
        heap = [(-dis[0][0], 0, 0)]
        visited = [[False] * m for _ in range(n)]
        visited[0][0] = True
        
        while heap:
            safeness, x, y = heapq.heappop(heap)
            safeness = -safeness
            
            if x == n - 1 and y == m - 1:
                return safeness
            
            for k in range(4):
                r, c = x + dx[k], y + dy[k]
                if 0 <= r < n and 0 <= c < m and not visited[r][c]:
                    visited[r][c] = True
                    heapq.heappush(heap, (-min(safeness, dis[r][c]), r, c))
        
        return 0