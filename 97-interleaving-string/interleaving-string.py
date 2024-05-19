class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n = len(s1)
        m = len(s2)
        if n+m != len(s3):
            return False
        dp = [[-1]*(m+1) for _ in range(n+1)]
        def solve(i,j):
            if i == n:
                return s2[j:] == s3[i+j:]
            if j == m:
                return s1[i:] == s3[i+j:]
            if i >= n or j >= m :
                return False
            if dp[i][j] != -1:
                return dp[i][j]
            if s1[i] == s2[j] == s3[i+j]:
                dp[i][j] =  solve(i+1,j) or solve(i,j+1)
            elif s1[i]==s3[i+j]:
                dp[i][j] =  solve(i+1,j)
            elif s2[j]==s3[i+j]:
                dp[i][j] =  solve(i,j+1)
            else:
                dp[i][j] = False
            return dp[i][j]

        return solve(0,0)