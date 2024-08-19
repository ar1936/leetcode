class Solution:
    def minimumEffortPath(self, grid: List[List[int]]) -> int:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        n = len(grid)
        m = len(grid[0])
        heap = []
        heapq.heappush(heap, (0,0,0))
        effort = [[float('inf')]*m for _ in range(n)]
        effort[0][0] = 0
        while heap:
            d, x, y = heapq.heappop(heap)
            if x == n-1 and y == m-1:
                return d 
            for k in range(4):
                new_x, new_y = dx[k] + x , dy[k] + y
                if 0<=new_x<n and 0<=new_y<m:
                    new_d = max(d, abs(grid[new_x][new_y] - grid[x][y]))
                    if new_d < effort[new_x][new_y]:
                        heapq.heappush(heap, (new_d, new_x, new_y))
                        effort [new_x][new_y] = new_d
        return 0