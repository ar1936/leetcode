class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        dp = [[-1]*(s//2+1) for _ in range(len(nums)+1)]
        if s%2==1:
            return False
        def solve(ind, su):
            if su == s//2:
                return True
            if ind>=len(nums) or su>s//2:
                return False
            if dp[ind][su] != -1:
                return dp[ind][su]
            if su + nums[ind]<=s//2:
                dp[ind][su] = solve(ind+1, su+nums[ind]) or solve(ind+1, su)
            else:
                dp[ind][su] = solve(ind+1, su)
            return dp[ind][su]
        return solve(0,0)