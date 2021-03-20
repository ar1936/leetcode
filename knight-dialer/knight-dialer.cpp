// class Solution {
// public:
//   int knightDialer(int n) {
//     unsigned int arr[9] = {1,1,1,1,1,1,1,1,1};
//     if(n==1) return 10;
//     unsigned int mod = 1000000007;
    
//     while(--n){
//       unsigned int narr[9];
//       narr[0] = (arr[4] + arr[5])%mod;
//       narr[1] = (arr[7] + arr[5])%mod;
//       narr[2] = (arr[6] + arr[8])%mod;
//       narr[3] = (arr[4] + arr[7])%mod;
//       narr[4] = (arr[3] + arr[0] + arr[8])%mod;
//       narr[5] = (arr[1] + arr[0] + arr[6])%mod;
//       narr[6] = (arr[2] + arr[5])%mod;
//       narr[7] = (arr[1] + arr[3])%mod;
//       narr[8] = (arr[4] + arr[2])%mod;
      
//       for(int i = 0 ; i < 9; i++) arr[i] = narr[i];
//     }
    
//     for(int i = 1 ; i < 9; i++) arr[0] = (arr[i] + arr[0])%mod;
//     return arr[0];
//   }
// };


class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> keypad{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{4,2}};
        vector<vector<int>> dp(10,vector<int>(n+1,0));
        for(int i=0;i<10;i++) {
            dp[i][1]=1;
        }
        if(n==1) return 10;
        for(int j=2;j<=n;j++) {
            for(int i=0;i<10;i++) {
                for(int k=0;k<keypad[i].size();k++) {
                    dp[i][j]=(dp[i][j]+dp[ keypad[i][k] ][j-1])%1000000007;
                }
            }
        }
        int ans=0;
        for(int i=0;i<10;i++) {
            ans=(ans+dp[i][n])%1000000007;
        }
        return ans;
    }
};