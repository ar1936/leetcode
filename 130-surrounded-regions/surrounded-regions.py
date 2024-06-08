class Solution:
    def solve(self, mat: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """ 
        n = len(mat)
        m = len(mat[0])
        def dfs(x,y,char):
            if x<0 or x>=n or y>=m or y<0 or mat[x][y] !='O':
                return 
            mat[x][y] = char
            for r,c in [(0,1),(1,0),(0,-1),(-1,0)]:
                dfs(x+r,y+c,char)

        for i in range(n):
            if mat[i][m-1] == 'O':
                dfs(i,m-1,'T')
            if mat[i][0] == 'O':
                dfs(i,0,'T')

        for i in range(m):
            if mat[0][i] == 'O':
                dfs(0,i,'T')
            if mat[n-1][i] == 'O':
                dfs(n-1,i,'T')

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 'O':
                    dfs(i,j, 'X')
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 'T':
                    mat[i][j] = 'O'