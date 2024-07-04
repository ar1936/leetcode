class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        indegree = [0]*(n)
        mp = defaultdict(list)
        for r1, r2 in relations:
            mp[r1-1].append(r2-1)
            indegree[r2-1] += 1
        heap = []
        ans = time[:]
        cnt = 0
        for i in range(n):
            if indegree[i] == 0:
                heapq.heappush(heap,(time[i],i))

        while heap:
            prev_val, prev_from = heapq.heappop(heap)
            for curr_node in mp[prev_from]:
                total_time = time[curr_node] + prev_val
                indegree[curr_node]-=1
                if ans[curr_node]<total_time:
                    ans[curr_node] = total_time
                if indegree[curr_node] == 0:
                    heapq.heappush(heap,(total_time,curr_node))
        
        return max(ans)
