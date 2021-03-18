class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int t[n+1][n+1];
        // memset(t,1000,sizeof(t)); // here i assume that INT_MAX=1000000
        int ans=INT_MAX;
        // for(int j=1;j<=n;j++)
        // {
        //     t[n][j]=matrix[n-1][j-1];
        // }
        if(matrix.size()==1)
            return matrix[0][0];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(j==n-1)
                    matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j-1]);
                else if (j==0)
                    matrix[i][j]+=min(matrix[i+1][j],matrix[i+1][j+1]);
                else
                    matrix[i][j]+=min(matrix[i+1][j],min(matrix[i+1][j-1],matrix[i+1][j+1]));
                if(i==0)
                {
                    ans=min(matrix[i][j],ans);
                }
            }
        }
        return ans;
        
    }
};