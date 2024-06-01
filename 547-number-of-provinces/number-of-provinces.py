class Solution:
    def findCircleNum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        parent = [i for i in range(n)]
        rank = [0]*n
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def Union(x,y):
            root1 = find(x)
            root2 = find(y)
            if root1!=root2:
                if rank[root1]<rank[root2]:
                    parent[root1] = root2
                elif rank[root1]>rank[root2]:
                    parent[root2] = root1
                else:
                    parent[root2] = root1
                    rank[root1] += 1
        
        for i in range(n):
            for j in range(i+1,n):
                if grid[i][j] == 1:
                    Union(i,j)
        return len(set(find(i) for i in range(n)))
