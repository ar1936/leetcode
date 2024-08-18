from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [-1]*10000000
        def backtrack(current_sum: int):
            if current_sum == target:
                return 1
            if current_sum > target:
                return 0 
            if dp[current_sum] !=-1:
                return dp[current_sum]
            tmp = 0
            for i in range(len(nums)):
               tmp += backtrack(current_sum + nums[i])
            dp[current_sum] = tmp
            return dp[current_sum]
        return backtrack(0)
