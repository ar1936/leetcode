class Solution:
    def coinChange(self, c: List[int], a: int) -> int:
        dp = [[-1]*(len(c)+1) for _ in range(a+1)]
        def solve(ind, su):
            if su == a:
                return 0
            if su>a or ind>=len(c):
                return 10**9
            if dp[su][ind] != -1:
                return dp[su][ind]
            if c[ind] + su <= a:
                dp[su][ind] = min(solve(ind,su+c[ind])+1, solve(ind+1,su))
            else:
                dp[su][ind] =  solve(ind+1,su)
            return dp[su][ind]
        return -1 if solve(0,0) == 10**9 else solve(0,0)