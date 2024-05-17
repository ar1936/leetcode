class Solution:
    def rob(self, nums: List[int]) -> int:
        def solve(ind,sz, dp):
            if ind > sz-1:
                return 0
            if dp[ind]!=-1:
                return dp[ind]
            dp[ind] = max(solve(ind+2,sz,dp)+nums[ind], solve(ind+1,sz,dp))
            return dp[ind]
        if len(nums)<=3:
            return max(nums)
        dp1 = [-1] * (len(nums)+1)
        dp2 = [-1] * (len(nums)+1)
        solve(0,len(nums)-1, dp1)
        solve(1, len(nums), dp2)
        return  max(dp1+dp2)