class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int total = 0;
        int n = stones.size();
        for(int i = 0;i<n;i++) {
            total+=stones[i];
        }
        sum = total/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i =1;i<=n;i++) {
            for(int j = 1;j<=sum;j++) {
                if(stones[i-1]>j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
                }
            }
        }
        return total-(2*dp[n][sum]);

    }
};