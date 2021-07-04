class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>mat(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==1||j==1)
                    mat[i][j]=1;
                else
                    mat[i][j]=0;
            }
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                mat[i][j]+=mat[i-1][j]+mat[i][j-1];
            }
        }
        return mat[m][n];
    }
};