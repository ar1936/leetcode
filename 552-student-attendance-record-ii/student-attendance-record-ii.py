class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 10**9+7
        def solve(p,cnt_a,cnt_l,dp):
            
            if  cnt_a>=2 or cnt_l>=3:
                return 0
            
            if p == 0:
                return 1
            
            if dp[p][cnt_a][cnt_l]!=-1:
                return dp[p][cnt_a][cnt_l]
            cnt = 0
            cnt = solve(p-1,cnt_a,0,dp)
            if cnt_a<1: 
                cnt  = (cnt + solve(p-1,cnt_a+1,0,dp))%mod
            if cnt_l<2:      
                cnt  = (cnt + solve(p-1,cnt_a,cnt_l+1,dp))%mod

            dp[p][cnt_a][cnt_l] = cnt
            return cnt

        dp = [[[-1]*3 for j in range(2)] for k in range(n+1)]
        return solve(n,0,0,dp)


