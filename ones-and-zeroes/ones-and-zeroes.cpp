class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      int sz = strs.size();
      int one[sz], zero[sz];
      for (int i = 0; i < sz; ++i) {
        int c1 = 0, c2 = 0;
        for (char c : strs[i]) {
          if (c == '1') c2++;
          if (c == '0') c1++;
        }
        zero[i] = c1, one[i] = c2;
      }
      int dp[m + 1][n + 1];
      memset(dp, 0, sizeof dp);
      for (int k = 0; k < sz; ++k) {
        for (int i = m; i >= zero[k]; --i) {
          for (int j = n; j >= one[k]; --j) {
              dp[i][j] = max(dp[i][j], dp[i - zero[k]][j - one[k]] + 1);
          }
        }
      }
      return dp[m][n];
    }
};