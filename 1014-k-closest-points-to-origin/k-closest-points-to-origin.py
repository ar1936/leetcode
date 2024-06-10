class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        heapq.heapify(heap)
        for p in points:
            dis = math.sqrt(p[1]**2 + p[0]**2)
            heapq.heappush(heap,(-1*dis,p))
            if len(heap)>k:
                heapq.heappop(heap)
        ans = []
        while heap:
            val = heapq.heappop(heap)
            ans.append(val[1])
        return ans
