class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        dx = [0,0,1,-1]
        dy = [-1,1,0,0]
        q = deque()
        visited = set()
        n = len(rooms)
        m = len(rooms[0])
        for i in range(n):
            for j in range(m):
                if rooms[i][j] == 0:
                    q.append((i,j, 0))
                    visited.add((i,j))
        
        while q:
            x,y,d = q.popleft()
            rooms[x][y] = d
            for k in range(4):
                curr_x, curr_y = x + dx[k], y + dy[k]
                if 0<=curr_x<n and 0<=curr_y<m and (curr_x,curr_y) not in visited and rooms[curr_x][curr_y] != -1:
                    visited.add((curr_x,curr_y))
                    q.append((curr_x, curr_y, d+1))
        return rooms