class Solution {
int dp[301][5001];
 int get_ans(int n, int amount, vector < int > & v) {
   if (n == 0 || amount <= 0) {
     if (amount == 0) {
       return 1;
     }
     return 0;
   }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0)
            {
                dp[i][j]=1;
            }
        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(j>=v[i-1]){
                dp[i][j]=dp[i][j-v[i-1]]+dp[i-1][j];
            }    
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
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