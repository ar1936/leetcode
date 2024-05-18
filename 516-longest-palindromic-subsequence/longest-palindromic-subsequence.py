class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        st = s[::-1]
        dp = [[-1]*(n+1) for _ in range(n+1)]
        def solve(i,j):
            if i == n or j == n:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            if s[i] == st[j]:
                dp[i][j] = solve(i+1,j+1)+1
            else:
                dp[i][j] = max(solve(i+1,j),solve(i,j+1))
            return dp[i][j] 
        return solve(0,0)