class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = [[] for _ in range(n)]
        for e1, e2, v in flights:
            graph[e1].append((e2,v))
        dist = [10**9]*n
        dist[src] = 0
        q = deque()
        q.append((0,src))
        step = 0
        while step<=k and  q:
            for _ in range(len(q)):
                d,no = q.popleft()
                for node, v in graph[no]:
                    total_dist = d+v
                    if dist[node]>=total_dist:
                        dist[node] = total_dist
                        q.append((total_dist, node))
            step+=1
        
        return -1 if dist[dst] == 10**9 else dist[dst]