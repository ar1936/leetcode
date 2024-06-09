class Solution:
    def canFinish(self, n: int, courses: List[List[int]]) -> bool:
        adj = defaultdict(list)
        indegree = [0]*n
        for dest, src in courses:
            adj[src].append(dest)
            indegree[dest] += 1
        queue = deque([i for i in range(n) if indegree[i]==0])
        cnt = 0
        while queue:
            u = queue.popleft()
            cnt+=1
            for v in adj[u]:
                indegree[v]-=1
                if indegree[v] == 0:
                    queue.append(v)
        return cnt == n
