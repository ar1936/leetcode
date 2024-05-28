class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid),len(grid[0])
        q = []
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    q.append((i,j))
                    grid[i][j] = '0'
                    while q:
                        sc,sr = q.pop()
                        for (x,y) in [(0,1),(1,0),(0,-1),(-1,0)]:
                            new_sc,new_sr = x+sc, y+sr
                            if 0<=new_sc<n and 0<=new_sr<m and grid[new_sc][new_sr] == '1':
                                grid[new_sc][new_sr] = '0'
                                q.append((new_sc,new_sr))
                    if len(q) == 0:
                        ans+=1
        return ans