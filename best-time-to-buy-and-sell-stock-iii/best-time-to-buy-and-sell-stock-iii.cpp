
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(2));
        for(int i=0;i<n+1;i++){
            dp[i][0].first=0;
            dp[i][1].first=0;
            dp[i][0].second=INT_MIN;
            dp[i][1].second=INT_MIN;
        }
        for(int i=1;i<n+1;i++){
            dp[i][1].first=max(dp[i-1][1].first,dp[i-1][1].second+prices[i-1]);
            dp[i][1].second=max(dp[i-1][1].second,dp[i-1][0].first-prices[i-1]);
            dp[i][0].first=max(dp[i-1][0].first,dp[i-1][0].second+prices[i-1]);
            dp[i][0].second=max(dp[i-1][0].second,-prices[i-1]);
        }
        return dp[n][1].first;
    }
};



