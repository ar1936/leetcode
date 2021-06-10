            //Greedy Approach

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size(),ans=0,temp=prices[0];
//         if(n==1)
//             return 0;
//         for(int i=0;i<n;i++){
//             if(temp>prices[i])
//                 temp=prices[i];
//             else
//                 ans=max(ans,prices[i]-temp);
//         }
//         return ans;
//     }
// };

                //Dp approach 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
            dp[i][1]=INT_MIN;
        }
        for(int i=1;i<n+1;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
            dp[i][1]=max(dp[i-1][1],-prices[i-1]);
        }
        return dp[n][0];
    }
};
