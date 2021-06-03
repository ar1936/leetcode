class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string st=s;
        reverse(st.begin(),st.end());
        int size=s.size();
        vector<vector<int>>dp(size+1,vector<int>(size+1,0));
        for(int i=1;i<=size;i++){
           for(int j=1;j<=size;j++){
                if(s[i-1]==st[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
               else
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
        return dp[size][size];
    }
};