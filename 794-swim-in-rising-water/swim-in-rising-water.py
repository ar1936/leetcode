class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        n = len(grid)
        m = len(grid[0])
        time = [[float('inf')]* m for _ in range(n)]
        heap = []
        heapq.heappush(heap,(grid[0][0], 0,0))
        ans = 0
        while heap:
            t, x,y = heapq.heappop(heap)
            ans  = max(ans, t)
            if x == n- 1 and y == m -1:
                return ans 
            for k in range(4):
                r,c = x+dx[k], y + dy[k]
                if 0<=r<n and 0<=c<m:
                    new_t = grid[r][c]
                    if time[r][c] > new_t:
                        heapq.heappush(heap,(new_t, r, c))
                        time[r][c] = new_t
        return ans