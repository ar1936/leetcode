class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        q = deque()
        q.append((start[0],start[1]))
        visited = set()
        visited.add((start[0],start[1]))
        while q:
            x,y = q.popleft()
            if x == destination[0] and y == destination[1]:
                return True
            for i in range(4):
                r = x
                c = y
                while 0<=r<len(maze) and 0<=c<len(maze[0]) and maze[r][c] == 0:
                    r+=dx[i]
                    c+=dy[i]
                r-=dx[i]
                c-=dy[i]
                if (r,c) not in visited:
                    visited.add((r,c))
                    q.append((r,c))
        return False