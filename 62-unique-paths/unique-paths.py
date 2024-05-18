class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def solve(i,j,dp):
            if i >= n-1 or j >= m-1 :
                return 1
            if dp[i][j] != -1:
                return dp[i][j]
            dp[i][j] = solve(i+1,j,dp)  + solve(i,j+1,dp) 
            return dp[i][j]

        dp = [[-1] * (m+1) for _ in range(n+1)]
        return solve(0,0,dp)