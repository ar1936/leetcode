class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        max_subarray_length = -10**9
        total_sum = sum(nums)
        
        # If the sum of the entire array is less than x, it's impossible to reach the target
        if total_sum < x:
            return -1
        
        left = 0
        current_sum = 0
        
        for right in range(len(nums)):
            current_sum += nums[right]
            
            # Shrink the window from the left if current_sum exceeds the target (total_sum - x)
            while current_sum > total_sum - x:
                current_sum -= nums[left]
                left += 1
            
            # If we found a subarray with the exact sum of (total_sum - x)
            if current_sum == total_sum - x:
                max_subarray_length = max(max_subarray_length, right - left + 1)
        
        # If no valid subarray was found, return -1. Otherwise, return the minimum operations.
        return -1 if max_subarray_length == -10**9 else len(nums) - max_subarray_length
