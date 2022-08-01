class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(n,vector<int>(m,1));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[n-1][m-1];
    }
};