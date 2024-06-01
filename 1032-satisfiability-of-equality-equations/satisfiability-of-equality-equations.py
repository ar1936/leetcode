class Solution:
    def equationsPossible(self, s: List[str]) -> bool:
        parent = [i for i in range(150)]
        rank = [0]*150
        def find(x):
            if parent[x]!=x:
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
                    parent[root1] = root2
                    rank[root2] += 1 
                
        for st in s:
            if st[1:3] == "==":
                union(ord(st[0]),ord(st[-1]))
        for st in s:
            if st[1:3] == "!=":
                if find(ord(st[0])) == find(ord(st[-1])):
                    return False
                
        return True