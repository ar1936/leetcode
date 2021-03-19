// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int dp[amount+1];
//         dp[0] = 1;
//         for (int coin : coins) {
//             for (int i = 1; i <= amount; i++) {
//                 if (i >= coin) {
//                     dp[i] += dp[i - coin];    
//                 }
//             }
//         }
//         return dp[amount];
//     }
// };


// // class Solution { // Coin Change 2
// //     public int change(int amount, int[] coins) {
// //         int[] dp = new int[amount + 1];
// //         dp[0] = 1;
// //         for (int coin : coins) {
// //             for (int i = 1; i <= amount; i++) {
// //                 if (i >= coin) {
// //                     dp[i] += dp[i - coin];    
// //                 }
// //             }
// //         }
// //         return dp[amount];
// //     }
// // }



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
//         for (const auto  c : coins) 
//             for (int i = c; i <= amount; ++i) 
//                 dp[i] += dp[i - c];    
        
        
        for (int i=1; i<=coins.size();i++) {
            for (int j=coins[i-1]; j<=amount;j++) {
                // if (i >=coins[j-1]) 
                    dp[j] += dp[j - coins[i-1]];
            }
        }
        
        
        return dp[amount];
    }
};

// class Solution {
// public:
//      int combinationSum4(vector<int>& nums, int target) {
//         unsigned int t[target+1];
//         memset(t,0,sizeof(t));
//         t[0] = 1;
//         for (int i = 1; i <= target; ++i) {
//             for (int j=1; j<=nums.size();j++) {
//                 if (i >=nums[j-1]) 
//                     t[i] += t[i - nums[j-1]];
//             }
//         }
        
//         return t[target];
//     }
    
// };

