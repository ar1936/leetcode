class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1]*len(text2) for _ in range(len(text1))]
        # for i in range(len(text1)+1):
        #     dp[i][0] = 0
        # for j in range(len(text2)+1):
        #     dp[0][j] = 0
        def solve(n,m):
            if n == len(text1) or m == len(text2):
                return 0
            if dp[n][m]!=-1:
                return dp[n][m]
            if text1[n] == text2[m]:
                dp[n][m] = solve(n+1,m+1)+1
            else:
                dp[n][m] = max(solve(n+1,m),solve(n,m+1))
            return dp[n][m]
        return solve(0,0)