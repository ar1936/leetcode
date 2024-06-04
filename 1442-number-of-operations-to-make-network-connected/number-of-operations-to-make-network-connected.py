class Solution:
    def makeConnected(self, n: int, con: List[List[int]]) -> int:
        m = len(con)
        if n > m+1:
            return -1
        parent = [i for i in range(n)]
        rank = [0]*n
        def find(x):
            if parent[x]!=x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x,y):
            root1 = find(x)
            root2 = find(y)
            if root1!=root2:
                if rank[root1]<rank[root2]:
                    parent[root1] = root2
                elif rank[root1]>rank[root2]:
                    parent[root2] = root1
                else:
                    parent[root2] = root1
                    root1 += 1
        for (i,j) in con:
            union(i,j)
        ans = 0
        # print(parent)
        for i in range(n):
            if parent[i]==i:
                ans+=1
        return ans - 1
