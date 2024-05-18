class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        dp = [[-1]*(len(s2)+1) for _ in range(len(s1)+1)]
        def solve(i,j):
            if i >= len(s1) and j >= len(s2):
                return 0
            if i == len(s1):
                return len(s2)-j
            if j == len(s2):
                return len(s1)-i
            if dp[i][j]!=-1:
                return dp[i][j]
            if s1[i] == s2[j]:
                dp[i][j] = solve(i+1,j+1)
            else:
                dp[i][j] = min(solve(i+1,j+1), solve(i+1,j), solve(i,j+1))+1
            return dp[i][j] 
        return solve(0,0)