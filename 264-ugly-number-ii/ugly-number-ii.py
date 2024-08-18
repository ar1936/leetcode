class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1]*n
        p2, p3, p5 = 0,0,0 
        for i in range(1,n):
            ugly_num = min(dp[p2]*2, dp[p3]*3, dp[p5]*5)
            dp[i] = ugly_num
            if ugly_num == dp[p2]*2:
                p2+=1
            if ugly_num == dp[p3]*3:
                p3+=1
            if ugly_num == dp[p5]*5:
                p5+=1
        return dp[-1]