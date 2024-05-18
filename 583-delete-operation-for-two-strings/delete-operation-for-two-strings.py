class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        n = len(s1)
        m = len(s2)
        dp = [[-1]*m for _ in range(n)]
        def solve(i,j):
            if i == n and j == m:
                return 0
            if i == n :
                return m - j
            if j == m :
                return n - i
            if dp[i][j] != -1:
                return dp[i][j]
            if s1[i] == s2[j]:
                dp[i][j] = solve(i+1,j+1)
            else:
                dp[i][j] =  1 + min(solve(i+1,j), solve(i, j+1))
            return dp[i][j]
        return solve(0,0)