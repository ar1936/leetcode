class Solution:
    def change(self, a: int, c: List[int]) -> int:
        dp = [[-1]* (len(c)+1) for _ in range(a+1)]
        def solve(ind, su):
            if a == su:
                return 1 
            if ind>=len(c) or su>a:
                return 0 
            if dp[su][ind] != -1:
                return dp[su][ind]
            if c[ind] + su <= a:
                dp[su][ind] =  solve(ind,su+c[ind]) + solve(ind+1, su)
            else:
                dp[su][ind] =  solve(ind+1, su)
            return dp[su][ind]
        return solve(0,0)