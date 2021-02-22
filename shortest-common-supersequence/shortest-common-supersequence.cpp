class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        int t[m+1][n+1];
        memset(t,0,sizeof(t));
        string s;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                    t[i][j]=t[i-1][j-1]+1;
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        int i=m,j=n;
        while(i>0&&j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])       //if(t[i-1][j]>t[i][j-1])
                {
                    s.push_back(str1[i-1]);
                    i--;
                }
                else
                {
                    s.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0)
        {
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};