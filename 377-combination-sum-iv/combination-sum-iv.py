from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [None] * (target + 1)
        
        def backtrack(current_sum: int) -> int:
            if current_sum == target:
                return 1
            if current_sum > target:
                return 0
            if dp[current_sum] is not None:
                return dp[current_sum]
            
            total_combinations = 0
            for num in nums:
                total_combinations += backtrack(current_sum + num)
            
            dp[current_sum] = total_combinations
            return dp[current_sum]
        
        return backtrack(0)
