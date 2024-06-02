class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)+1
        parent = [i for i in range(n)]
        rank = [0]*n
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x,y):
            root1 = find(x)
            root2 = find(y)
            if root1 != root2:
                if rank[root1]<rank[root2]:
                    parent[root1] = root2
                elif rank[root1]>rank[root2]:
                    parent[root2] = root1
                else:
                    parent[root2] = root1
                    rank[root1] +=1
        
        ans = []
        for e in edges:
            if find(e[0]) == find(e[1]):
                ans.append(e)
            else:
                union(e[0],e[1])
        
        return ans[-1]
