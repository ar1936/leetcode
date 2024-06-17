class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        ans = [[float('inf')]*m for _ in range(n)]
        pq = []
        heapq.heappush(pq,(0,0,0))
        while pq:
            parent_cost, parent_x, parent_y = heapq.heappop(pq)
            for (i,j) in [(0,1),(1,0),(0,-1),(-1,0)]:
                new_x = i + parent_x
                new_y = j + parent_y
                if 0<=new_x<n and 0<=new_y<m:
                    total_cost = grid[new_x][new_y] + parent_cost
                    if total_cost<ans[new_x][new_y]:
                        ans[new_x][new_y] = total_cost
                        heapq.heappush(pq,(total_cost,new_x,new_y))
        return ans[n-1][m-1]