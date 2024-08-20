class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        n = len(maze)
        m = len(maze[0])
        visited = set()
        q = deque()
        for i in range(n):
            if [i,0] != entrance:
                if maze[i][0] == '.':
                    q.append((0,i,0)) 
                    visited.add((0,i,0))
            if [i,m-1] != entrance:
                if maze[i][m-1] == '.':
                    q.append((0,i,m-1)) 
                    visited.add((0,i,m-1))
               
        for j in range(m):
            if [0,j] != entrance:
                if maze[0][j] == '.':
                    q.append((0,0,j))
                    visited.add((0,j))
            if [n-1,j] != entrance:
                if maze[n-1][j] == '.':
                    q.append((0,n-1,j))
                    visited.add((n-1,j))
                    
        while q:
            d, x, y = q.popleft()
            if x == entrance[0] and y == entrance[1]:
                return d 
            for k in range(4):
                r,c = x + dx[k], dy[k] + y
                if 0 <= r < n and 0<=c<m and (r,c) not in visited and maze[r][c] != '+':
                    visited.add((r,c))
                    q.append((d+1, r,c))
        return -1 