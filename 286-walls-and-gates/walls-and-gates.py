class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        n = len(rooms)
        m = len(rooms[0])
        dx = [0,0,-1,1]
        dy = [1,-1,0,0]
        q = deque()
        visited = set()
        for i in range(n):
            for j in range(m):
                if rooms[i][j] == 0:
                    q.append((i,j,0))
                    visited.add((i,j))
        
        while q:
            x,y, step = q.popleft()
            for k in range(4):
                new_x,new_y, new_step = x+dx[k] , y + dy[k], step + 1
                if 0<=new_x<n and 0<=new_y<m and rooms[new_x][new_y] != -1:
                    if (new_x,new_y) not in visited:
                        visited.add((new_x,new_y))
                        q.append((new_x,new_y,new_step))
                        rooms[new_x][new_y] = new_step
        return rooms