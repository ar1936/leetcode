class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        max_val = float('-inf')
        min_val = float('inf')
        for n in nums:
            max_val = max(max_val, n)
            min_val = min(min_val, n)
        
        prev_mid = max_val
        error = float('inf')
        
        while error > 0.00001:
            mid = (max_val + min_val) * 0.5
            if self.check(nums, mid, k):
                min_val = mid
            else:
                max_val = mid
            error = abs(prev_mid - mid)
            prev_mid = mid
        
        return min_val

    def check(self, nums: List[int], mid: float, k: int) -> bool:
        sum = 0
        prev = 0
        min_sum = 0
        
        for i in range(k):
            sum += nums[i] - mid
        
        if sum >= 0:
            return True
        
        for i in range(k, len(nums)):
            sum += nums[i] - mid
            prev += nums[i - k] - mid
            min_sum = min(prev, min_sum)
            if sum >= min_sum:
                return True
        
        return False
