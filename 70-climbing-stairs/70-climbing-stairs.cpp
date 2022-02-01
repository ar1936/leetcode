vector<int>dp(46,-1);
class Solution {
public:
    int solve(int n){
        if(n<0)
            return 0;
        if(n==0)
        return dp[n]=1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(n-1)+solve(n-2);
            
    }
    int climbStairs(int n) {
        solve(n);
        return dp[n];
    }
};