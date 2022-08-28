class Solution {
    int dp[1001];
int solve(vector<int>&cost, int ind){
    if(dp[ind]!=-1)
        return dp[ind];
    return dp[ind] = min(solve(cost,ind-1),solve(cost,ind-2))+cost[ind];
}
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        dp[0]=cost[0];
        dp[1]=cost[1];
        solve(cost,cost.size()-1);
        // for(auto x:dp){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};