class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int t[m+1][n+1];
        memset(t,0,sizeof(t));
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            sum+=grid[i-1][0];
            t[i][1]=sum;
        }
        sum=0;
	    for(int j=1;j<=n;j++)
	    {
            
            sum+=grid[0][j-1];
            t[1][j]=sum;
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
                t[i][j]=min(t[i-1][j],t[i][j-1])+grid[i-1][j-1];
            }
        }
        return t[m][n];
    }
    
};