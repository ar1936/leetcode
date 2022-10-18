class Solution {
int dp[13][10001];
int solve(int n , int amount , vector<int>&v){
       for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    dp[i][j]=1e9;
                }
                if(j==0){
                    dp[i][j]=0;
                }
            }
        }
     for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j>=v[i-1]){
                    dp[i][j]=min(dp[i][j-v[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }     
    return dp[n][amount];
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