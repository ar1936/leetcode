# class Solution:
#     def minimumEffortPath(self, grid: List[List[int]]) -> int:
#         n = len(grid)
#         m = len(grid[0])
#         adj = defaultdict(list)
#         dis = {}
#         for i in range(n):  
#             for j in range(m):
#                 dis[(i,j)] = 10**9
#                 for (u,v) in [(1,0),(0,1),(0,-1),(-1,0)]:
#                     x = i + u
#                     y = j + v
#                     if 0<=x<n and 0<=y<m:
#                         adj[(i,j)].append((x,y,grid[x][y]))
#         heap = [(0,(0,0))]
#         dis[(0,0)] = 0
#         while heap:
#             prev_dis, (prev_x,prev_y) = heapq.heappop(heap)
#             for (x,y,d) in adj[(prev_x,prev_y)]:
#                 total_dis = abs(grid[x][y] -  grid[prev_x][prev_y]) 
#                 if total_dis>=0 and total_dis<dis[(x,y)]:
#                     heapq.heappush(heap,(total_dis, (x,y)))
#                     dis[(x,y)] = total_dis
#         return dis[(n-1,m-1)]



class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])
        adj = defaultdict(list)
        dis = {(i, j): float('inf') for i in range(n) for j in range(m)}
        directions = [(1, 0), (0, 1), (0, -1), (-1, 0)]
        
        for i in range(n):
            for j in range(m):
                for u, v in directions:
                    x, y = i + u, j + v
                    if 0 <= x < n and 0 <= y < m:
                        effort = abs(heights[x][y] - heights[i][j])
                        adj[(i, j)].append((x, y, effort))
        
        heap = [(0, 0, 0)]  # (effort, x, y)
        dis[(0, 0)] = 0
        
        while heap:
            effort, x, y = heapq.heappop(heap)
            if (x, y) == (n - 1, m - 1):
                return effort
            for nx, ny, ne in adj[(x, y)]:
                new_effort = max(effort, ne)
                if new_effort < dis[(nx, ny)]:
                    heapq.heappush(heap, (new_effort, nx, ny))
                    dis[(nx, ny)] = new_effort
        
        return dis[(n - 1, m - 1)]