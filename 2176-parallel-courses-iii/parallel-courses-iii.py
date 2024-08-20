class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        indegree = [0]*n 
        graph = defaultdict(list)
        dist = time[:]
        for r1, r2 in relations:
            graph[r1-1].append((r2-1,time[r2-1]))
            indegree[r2-1]+=1
        ans = time[:]
        heap = []
        for i in range(n):
            if indegree[i] == 0:
                heapq.heappush(heap, (time[i], i))
        
        while heap:
            prev_time, prev_node = heapq.heappop(heap)
            for curr_node, curr_time in graph[prev_node]:
                indegree[curr_node] -= 1
                total_time = prev_time + curr_time
                if ans[curr_node]<total_time:
                    ans[curr_node] = total_time
                if indegree[curr_node] == 0:
                    heapq.heappush(heap, (total_time, curr_node)) 
        return max(ans)