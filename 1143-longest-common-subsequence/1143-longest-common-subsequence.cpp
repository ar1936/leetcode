class Solution {
    int dp[1001][1001];
    int solve(int n, int m , string &s1, string &s2){
        if(n==0||m==0){
            return 0;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=solve(n-1,m-1,s1,s2)+1;
        }
        else{
            return dp[n][m]=max(solve(n-1,m,s1,s2),solve(n,m-1,s1,s2));
        }
        return dp[n][m];
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        return solve(n,m,s1,s2);
    }
};