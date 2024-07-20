class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        parent = [i for i in range(n)]
        rank = [0]*n
        def find(x):
            if x!=parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x,y):
            root1 = find(x)
            root2 = find(y)
            if root1!=root2:
                if rank[root1]<rank[root2]:
                    parent[root2] = root1
                elif rank[root1]>rank[root2]:
                    parent[root1] = root2
                else:
                    parent[root2] = root1
                    rank[root1]+=1

        logs.sort(key = lambda x : x[0])
        last_time = 0
        for t,a,b in logs:
            if find(a)!=find(b):
                union(a,b)
                last_time = t
            else:
                mp = defaultdict(int)
                for i in range(n):
                    mp[find(i)]+=1
                if len(mp)==1 and mp[find(0)]==n:
                    return last_time
        mp = defaultdict(int)
        for i in range(n):
            mp[find(i)]+=1
        if len(mp)==1 and mp[find(0)]==n:
            return last_time
        return -1
                