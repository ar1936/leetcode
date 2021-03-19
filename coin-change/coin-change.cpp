class Solution {
  public:
    int coinChange(vector < int > & coins, int amount) {

      int n = coins.size();
      long long t[n + 1][amount + 1];
      for (int i = 0; i <= n; i++)
        t[i][0] = 0;

      for (int j = 1; j <= amount; j++)
        t[0][j] = INT_MAX;

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
          if (coins[i - 1] <= j)
            t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
          else
            t[i][j] = t[i - 1][j];
        }
      }
      if (t[n][amount] == INT_MAX) return -1;
      return t[n][amount];
    }
};

// class Solution {
//   public:
//     int solve(vector < int > coin, int size, int amount) {
//       if (amount == 0)
//         return 0;
//       if (amount < 0)
//         return INT_MAX/2;
//       if (size == 0)
//         return INT_MAX/2;
//       int t[size + 1][amount + 1];
//       memset(t, -1, sizeof(t));
//       for (int i = 0; i <= size; i++)
//         t[i][0] = 0;

//       for (int j = 1; j <= amount; j++)
//         t[0][j] = INT_MAX/2;
//       if (t[size][amount] != -1)
//         return t[size][size];

//       if (coin[size - 1] <= amount)
//         return t[size][amount] = min(1 + solve(coin, size, amount - coin[size - 1]), solve(coin, size - 1, amount));
//       else
//         return t[size][amount] = solve(coin, size - 1, amount);
//       return t[size][amount];
//     }
//   int coinChange(vector < int > & coins, int amount) {
//     int m=solve(coins, coins.size(), amount);
      
//     if(m>=INT_MAX/2)  // this is use of edge test case when coin=2 or target=3, in this case there is no solution so we have to return -1;
//         return -1;
//     else 
//         return m;
//   }
// };  

