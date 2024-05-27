class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        arrLen = min(arrLen-1,steps)
        mod = 10**9+7
        def solve(stay,n,dp):
            if n == steps and stay == 0:
                return 1

            if stay<0 or stay>arrLen or n == steps:
                return 0
            if dp[n][stay]!=-1:
                return dp[n][stay]
            dp[n][stay] = (solve(stay,n+1,dp)%mod+solve(stay+1,n+1,dp)%mod+solve(stay-1,n+1,dp)%mod)%mod
            return dp[n][stay]
        dp = [[-1]*(arrLen+1) for _ in range(steps+1)]
        return solve(0,0,dp)
