class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        q = deque()
        visited = set()
        q.append((0,0,0, grid[0][0]))
        visited.add((0,0, grid[0][0]))
        while q:
            x, y , step , used_k = q.popleft()
            if x == n -1 and y == m -1 :
                return step 
            for z in range(4):
                r,c = x+dx[z],  y + dy[z]
                if 0<=r<n and 0<=c<m:
                    new_k = used_k + grid[r][c]
                    if new_k <=k  and (r,c,new_k) not in visited:
                        q.append((r,c,step+1,new_k))
                        visited.add((r,c,new_k))
        return -1 