class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      int size = strs.size();
      int one[size], zero[size];
      for (int i = 0; i < size; ++i) {
        int count0 = 0, count1 = 0;
        for (char c : strs[i]) {
          if (c == '1') count1++;
          if (c == '0') count0++;
        }
        zero[i] = count0, one[i] = count1;
      }
      int dp[m + 1][n + 1];
      memset(dp, 0, sizeof(dp));
      for (int k = 0; k < size; ++k) {
        for (int i = m; i >= zero[k]; --i) {
          for (int j = n; j >= one[k]; --j) {
              dp[i][j] = max(dp[i][j], dp[i - zero[k]][j - one[k]] + 1);
          }
        }
      }
      return dp[m][n];
    }
};