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
        for (const auto & c : coins) 
            for (int i = c; i <= amount; ++i) 
                dp[i] += dp[i - c];    
        
        return dp[amount];
    }
};