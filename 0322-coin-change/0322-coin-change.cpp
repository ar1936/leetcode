class Solution {
int dp[13][10001];
int solve(int n , int amount , vector<int>&v){
      if(n==0||amount==0){
        if(n==0){
          return 1e9;
        }
        return 0;
      }
      if(dp[n][amount]!=-1)
          return dp[n][amount];
      if(amount>=v[n-1]){
        return dp[n][amount]=min(solve(n,amount-v[n-1],v)+1,solve(n-1,amount,v));
      }
      else{
        return dp[n][amount]=solve(n-1,amount,v);
      }
} 
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=-1;
            }
        }
        int ans=solve(n,amount,coins);
        if(ans==1e9)
          return -1;
        else
          return ans;
    }
};