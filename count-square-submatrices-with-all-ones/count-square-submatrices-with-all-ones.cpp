class Solution {
    int k_size_square(vector<vector<int>>pre_sum,int k){
        int count=0,n=pre_sum.size(),m=pre_sum[0].size();
        for(int i=k;i<n;i++){
            for(int j=k;j<m;j++){
                if(pre_sum[i][j]-pre_sum[i-k][j]-pre_sum[i][j-k]+pre_sum[i-k][j-k]==k*k)
                    count++;
            }
        }
        return count;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0,n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>pre_sum(n+1,vector<int>(m+1));
        pre_sum[1][1]=matrix[0][0];
        for(int i=2;i<=n;i++){
            pre_sum[i][1]=pre_sum[i-1][1]+matrix[i-1][0];
        }
        for(int j=2;j<=m;j++){
            pre_sum[1][j]=pre_sum[1][j-1]+matrix[0][j-1];
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                pre_sum[i][j]=+pre_sum[i-1][j]+pre_sum[i][j-1]-pre_sum[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        for(int k=1;k<=min(n,m);k++){
            ans+=k_size_square(pre_sum,k);
        }
        return ans;
    }
};