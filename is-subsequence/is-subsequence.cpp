class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length() , n=t.length(); 
        vector<vector<int>> lcs(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
               if(s[i-1]==t[j-1])  
                    lcs[i][j] = 1+lcs[i-1][j-1];
                else 
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        return lcs[m][n] == m;
    }
};
