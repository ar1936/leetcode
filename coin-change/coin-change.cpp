class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
long long dp[n+1][amount+1];
for(int i=0;i<=n;i++)
dp[i][0]=0;

      for(int j=1;j<=amount;j++)
        dp[0][j]=INT_MAX;
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if( dp[n][amount] == INT_MAX )return -1 ;
    return dp[n][amount];
    }
};









// int size=coins.size();
//         int  t[size+1][amount+1];
//         for(int i=0;i<size+1;i++)
//             t[i][0]=0;
//         for(int j=0;j<amount+1;j++)
//         {
//             t[0][j]=INT_MAX-1;
//         }
//         for(int j=1;j<amount+1;j++)
//         {
//             if(j%coins[0]==0)
//                 t[1][j]=j/coins[0];
//             else 
//                 t[1][j]=INT_MAX-1;
//         }
//         for(int i=1;i<size+1;i++)
//         {
//             for(int j=1;j<amount+1;j++)
//             {
//                 if(j<coins[i-1])
//                     t[i][j]=t[i-1][j];
//                 else 
//                     t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
//             }
//         }
//         if(t[size][amount]==INT_MAX-1)
//             return -1;
//         return t[size][amount];