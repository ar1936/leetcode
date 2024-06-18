class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        if n == 1 and m==1:
            return grid[0][0]
        queue = deque()
        queue.append((0,0,grid[0][0]))
        visited = set()
        visited.add((0,0, grid[0][0]))
        step = 0
        while queue:
            for _ in range(len(queue)):
                prev_x,prev_y, prev_k = queue.popleft()
                for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    curr_x , curr_y = prev_x + dx, prev_y + dy
                    if 0<=curr_x<n and 0<=curr_y<m:
                        total_used_obstacles = prev_k + grid[curr_x][curr_y]
                        if total_used_obstacles<=k:
                            if curr_x == n-1 and curr_y == m-1:
                                return step+1
                            if (curr_x,curr_y,total_used_obstacles) not in visited:
                                queue.append((curr_x,curr_y,total_used_obstacles))
                                visited.add((curr_x,curr_y,total_used_obstacles))
            step+=1
        return -1