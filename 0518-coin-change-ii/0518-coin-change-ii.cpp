class Solution {
    int dp[301][5001];
    int get_ans(int n, int amount, vector<int>&v){
      if(n==0||amount<=0){
        if(amount==0){
          return 1;
        }
        return 0;
      }
      if(dp[n][amount]!=-1)
        return dp[n][amount];
      if(amount>=v[n-1]){
         return dp[n][amount]=get_ans(n,amount-v[n-1],v) + get_ans(n-1,amount,v); 
      }
      else{
         return dp[n][amount]=get_ans(n-1,amount,v);
      }

     return dp[n][amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        for(int i=0;i<=n;i++){
          for(int j=0;j<=amount;j++){
            dp[i][j]=-1;
          }
        }
        return get_ans(n,amount,coins);   
    }
};