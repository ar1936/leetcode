class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        ans = 0
        def dfs(x, y):
            # If out of bounds or current cell in grid2 is not part of an island (not 1),
            # return True because we are not concerned with out-of-bound areas or non-island areas.
            if x < 0 or y < 0 or x >= n or y >= m or grid2[x][y] != 1:
                return True
            
            # If the corresponding cell in grid1 is water (0), return False because this means
            # the current island in grid2 cannot be considered a sub-island (part of it is not in grid1).
            if grid1[x][y] == 0:
                return False
            
            # Mark the current cell in grid2 as visited by setting it to -1 to avoid re-processing.
            grid2[x][y] = -1

            # Initialize result to True, assuming this part of the island is a valid sub-island.
            result = True
            
            # Explore all four possible directions (right, down, left, up).
            for a, b in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                # If any of the recursive DFS calls return False, it means a part of this island
                # in grid2 is not a sub-island (corresponding part in grid1 is water).
                # Hence, update result to False.
                if not dfs(x + a, y + b):
                    result = False
            
            # Return the result. If all parts of this island in grid2 correspond to land (1) in grid1,
            # result will remain True, otherwise it will be False.
            return result


        n = len(grid1)
        m = len(grid1[0])
        for i in range(n):
            for j in range(m):
                if grid2[i][j]==1:
                    if dfs(i,j):
                        ans+=1
        return ans

