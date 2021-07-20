class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& mat) {
        int n=mat.size(),ans=0;
        sort(mat.begin(),mat.end());
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(mat[i][1]>mat[j][1] && mat[i][0]>mat[j][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};


// for(int j=0;j<i;++j){
//                 if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]) dp[i] = max(dp[i], 1+dp[j]);
//             }