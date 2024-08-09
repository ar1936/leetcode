class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        n = len(grid)
        m = len(grid[0])
        heap = [(grid[0][0], 0, 0)]
        dist = [[10**9]*m for _ in range(n)]
        visited = set()
        visited.add((0,0))
        ans = grid[0][0]
        while heap:
            d, x,y= heapq.heappop(heap)
            ans = max(d,ans)
            if x == n-1 and y == m-1:
                return ans
            for k in range(4):
                new_x, new_y = x + dx[k] , y+dy[k]
                if 0<=new_x<n and 0<=new_y<m and (new_x, new_y) not in visited:
                    new_d = grid[new_x][new_y]
                    dist[new_x][new_y] = new_d
                    heapq.heappush(heap,(new_d, new_x,new_y))
                    visited.add((new_x,new_y))
        return ans