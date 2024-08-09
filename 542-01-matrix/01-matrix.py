class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        dx = [0,0,1,-1]
        dy = [1,-1,0,0]
        n = len(mat)
        m = len(mat[0])
        # for i in range(n):
        #     for j in range(m):
        # #         q = deque()
        #         visited = set()
        #         if mat[i][j] == 1:
        #             visited.add((i,j))
        #             q.append((i,j,0))
        #             while q:
        #                 x,y,s = q.popleft()
        #                 if mat[x][y] == 0:
        #                     mat[i][j] = s
        #                     break
        #                 for k in range(4):
        #                     new_x, new_y, new_step = x+dx[k], y+ dy[k], s  + 1
        #                     if 0<=new_x<n and 0<=new_y<m and (new_x, new_y) not in visited:
        #                         q.append((new_x, new_y, new_step))
        # return mat
        # ans = [row[:] for row in mat]
        q = deque()
        visited = set()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append((i,j,0))
                    visited.add((i,j))
        while q:
            x,y,s = q.popleft()
            for k in range(4):
                new_x, new_y, new_step = x + dx[k], y+ dy[k], s + 1
                if 0<=new_x<n and 0<=new_y<m and (new_x, new_y) not in visited:
                    q.append((new_x, new_y, new_step))
                    visited.add((new_x,new_y))
                    mat[new_x][new_y] = new_step
        return mat
