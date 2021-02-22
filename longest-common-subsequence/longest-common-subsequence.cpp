class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int t[m+1][n+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    t[i][j]=t[i-1][j-1]+1;
                else 
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
        
    }
};