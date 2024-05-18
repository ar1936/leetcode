class Solution:
    def coinChange(self, nums: List[int], amount: int) -> int:
        def solve(ind, sum, dp):
            if sum == amount:
                return 0
            if sum > amount:
                return 10**9
            if ind == len(nums):
                return 10**9
            if dp[ind][sum] != -1:
                return dp[ind][sum]
            if nums[ind]<=(amount-sum):
                dp[ind][sum] = min(solve(ind+1,sum,dp), solve(ind,sum+nums[ind],dp)+1)
            else:
                dp[ind][sum] = solve(ind+1,sum,dp)
            return dp[ind][sum]
        ans = 0
        dp = [[-1]*(amount+1) for _ in range(len(nums)+1)]
        ans = solve(0,0,dp)
        return -1 if ans == 10**9 else ans 