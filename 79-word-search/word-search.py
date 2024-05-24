class Solution:
    def exist(self, grid: List[List[str]], word: str) -> bool:
        n = len(grid)
        m = len(grid[0])
        def dfs(i,j,ind):
            if ind == len(word):
                return True
                
            if i<0 or i>=n or j<0 or j>=m or ind>=len(word) or  word[ind]!=grid[i][j]:
                return False
            
            tmp = grid[i][j]
            grid[i][j] = '#'
            flag = dfs(i,j+1,ind+1) or dfs(i,j-1,ind+1) or dfs(i+1,j,ind+1) or dfs(i-1,j,ind+1)

            grid[i][j] = tmp

            return flag     

        for i in range(n):
            for j in range(m):
                if grid[i][j] == word[0]:
                    if dfs(i,j,0):
                        return True
                    
        return False