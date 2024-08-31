class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        adj = defaultdict(list)
        prob = [0.0]*n
        for ind, (u,v) in enumerate(edges):
            adj[u].append((v, succProb[ind]))
            adj[v].append((u, succProb[ind]))

        heap = []
        prob[start_node] = 1.0
        heap.append((-1.0,start_node))
        heapq.heapify(heap)
        while heap:
            prev_prob, prev_node = heapq.heappop(heap)
            if prev_node == end_node:
                return -prev_prob
            for curr_node,curr_prob in adj[prev_node]:
                total_prob = -prev_prob*curr_prob
                if total_prob>prob[curr_node]:
                    heapq.heappush(heap,(-total_prob,curr_node))
                    prob[curr_node] = total_prob
        return 0.0

