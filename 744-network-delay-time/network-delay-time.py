class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = {}
        for t in times:
            adj.setdefault(t[0],[]).append([t[1],t[2]])
        heap = []
        heapq.heapify(heap)
        dis = [10**9]*(n+1)
        dis[k] = 0
        heapq.heappush(heap,(0,k))
        while heap:
            prev_dis, prev_node = heapq.heappop(heap)
            if prev_node in adj:
                for curr_node, curr_dis in adj[prev_node]:
                    total_dis = prev_dis + curr_dis
                    if total_dis < dis[curr_node]:
                        dis[curr_node] = total_dis
                        heapq.heappush(heap,(total_dis,curr_node))
        return -1 if max(dis[1:]) == 10**9 else max(dis[1:])