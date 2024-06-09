class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap =[]
        heapq.heapify(heap)
        n = len(nums)
        for i in range(n):
            heapq.heappush(heap,nums[i])
            if len(heap)>k:
                heapq.heappop(heap)
        return heap[0]