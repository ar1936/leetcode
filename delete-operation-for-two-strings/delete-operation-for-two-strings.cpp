class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        int t[m+1][n+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    t[i][j]=t[i-1][j-1]+1;
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return m+n-2*t[m][n];
    }
};