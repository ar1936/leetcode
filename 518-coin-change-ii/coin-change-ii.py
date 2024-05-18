class Solution:
    def change(self, find_sum: int, nums: List[int]) -> int:
        dp = [[-1]*(find_sum+1) for _ in range(len(nums)+1)]
        def solve(ind, su):

            if ind >= len(nums) or su>find_sum:
                return 0
            if su == find_sum:
                return 1
            if dp[ind][su]!=-1:
                return dp[ind][su]
            if nums[ind]<=find_sum:
                dp[ind][su] =  solve(ind+1,su) + solve(ind, su + nums[ind])
            else:
                dp[ind][su] = solve(ind+1, su) 
            return dp[ind][su]
        return solve(0,0)