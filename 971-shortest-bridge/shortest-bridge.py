class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        n = len(grid)
        m = len(grid[0])
        island_ind = set()
        def dfs(x,y):
            if x<0 or x>=n or y<0 or y>=m or grid[x][y] ==0:
                return 
            grid[x][y] = 0
            island_ind.add((x,y))
            for i in range(4):
                dfs(x+dx[i],y+dy[i])
            
        for i in range(n):
            flag = False
            for j in range(m):
                if grid[i][j] == 1:
                    dfs(i,j)
                    flag = True
                    break
            if flag:
                break

        q = deque()
        for (x,y) in island_ind:
            q.append((x,y,0))
        while q:
            r,c, cnt= q.popleft()
            if grid[r][c]==1:
                return cnt - 1
            for i in range(4):
                new_x, new_y = r+dx[i], c + dy[i]
                if new_x>=0 and new_x<n and new_y>=0 and new_y<m and (new_x,new_y) not in island_ind:
                    q.append((new_x,new_y,cnt+1))
                    island_ind.add((new_x,new_y))

        return  - 1