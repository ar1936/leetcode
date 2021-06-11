// last submission using pepcoding -> https://www.youtube.com/watch?v=4YjEHmw1MX0&ab_channel=PepcodingPepcoding


// greedy solution


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int least_price_before_today=INT_MAX;
        int price_if_sell_today=0;
        int max_price_till_now=0;
        for(int i=0;i<n;i++){
            if(prices[i]<least_price_before_today)
                least_price_before_today=prices[i];
            price_if_sell_today=prices[i]- least_price_before_today;
            if(max_price_till_now<price_if_sell_today)
               max_price_till_now=price_if_sell_today;
        }
        return max_price_till_now;
    }
};


                //Dp approach 

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2));
//         for(int i=0;i<n+1;i++){
//             dp[i][0]=0;
//             dp[i][1]=INT_MIN;
//         }
//         for(int i=1;i<n+1;i++){
//             dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i-1]);
//             dp[i][1]=max(dp[i-1][1],-prices[i-1]);
//         }
//         return dp[n][0];
//     }
// };


//             // copied solution from fun4leetcode (user name)

// class Solution {
// public:
//      int maxProfit(vector<int>prices) {
//         int T_i10 = 0, T_i11 = INT_MIN;

//         for (int price : prices) {
//             T_i10 = max(T_i10, T_i11 + price);
//             T_i11 = max(T_i11, -price);
//         }

//         return T_i10;
//     }
// };

//             //using kadane algorighm 
// class Solution {
//     int kadane_algo(vector<int> temp){
//         int ans=0,sum=0;
//         for(int i=0;i<temp.size();i++){
//             sum+=temp[i];
//             ans=max(ans,sum);
//             if(sum<=0)
//                 sum=0;
//         }
//         return ans;
//     }
// public:
//      int maxProfit(vector<int>prices) {
//          vector<int>temp;
//          for(int i=1;i<prices.size();i++){
//              temp.push_back(prices[i]-prices[i-1]);
//          }
//          return kadane_algo(temp);
//     }
// };