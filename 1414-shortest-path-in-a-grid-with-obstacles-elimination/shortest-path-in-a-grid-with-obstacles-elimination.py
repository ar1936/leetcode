from collections import deque
from typing import List

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        n, m = len(grid), len(grid[0])
        
        # Initialize the BFS queue and visited set
        queue = deque([(0, 0, 0, 0)])  # (x, y, steps, used_k)
        visited = set([(0, 0, 0)])  # (x, y, used_k)
        
        while queue:
            x, y, steps, used_k = queue.popleft()
            
            # If we reached the bottom-right corner, return the number of steps
            if x == n - 1 and y == m - 1:
                return steps
            
            # Explore all four directions
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                
                if 0 <= new_x < n and 0 <= new_y < m:
                    new_k = used_k + grid[new_x][new_y]
                    
                    # Continue only if the new position is within the allowed obstacle removal limit
                    if new_k <= k and (new_x, new_y, new_k) not in visited:
                        visited.add((new_x, new_y, new_k))
                        queue.append((new_x, new_y, steps + 1, new_k))
        
        # If no path is found
        return -1
