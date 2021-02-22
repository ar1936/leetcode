class Solution {
public:
    int minInsertions(string s1) {
        string s2=s1;
    reverse(s2.begin(),s2.end());
    int m=s1.size();
    int t[m+1][m+1];
    memset(t,0,sizeof(t));
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            t[i][j]=t[i-1][j-1]+1;
            else 
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return m-t[m][m];
        
        
    }
};





    