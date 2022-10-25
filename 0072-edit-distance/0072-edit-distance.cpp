int dp[501][501];
class Solution {
    int solve(string &s1, string &s2,int n , int m ){
         if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            return dp[n][m] = solve(s1,s2,n-1,m-1);
        }
        else{
            return dp[n][m] = min(solve(s1,s2,n-1,m),min(solve(s1,s2,n,m-1),solve(s1,s2,n-1,m-1)))+1;
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m=word2.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        return solve(word1,word2,n,m);
    }
};