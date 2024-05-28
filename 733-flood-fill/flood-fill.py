class Solution:
    def floodFill(self, grid: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        q = []        
        q.append((sr,sc))
        old_color = grid[sr][sc]
        grid[sr][sc] = color
        if old_color == color:
            return grid
        while q:
            old_sr, old_sc = q[-1]
            q.pop()
            for (x,y) in [(1,0),(0,1),(-1,0),(0,-1)]:
                new_sr,new_sc = x + old_sr, y + old_sc
                if 0<=new_sr<len(grid) and 0<=new_sc<len(grid[0]) and grid[new_sr][new_sc] == old_color:
                    q.append((new_sr,new_sc))
                    grid[new_sr][new_sc] = color
        return grid