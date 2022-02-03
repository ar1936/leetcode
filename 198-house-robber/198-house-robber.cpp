// class Solution {
//     int solve(vector<int>&v, int n,vector<int>&dp){
//         if(n<=0)
//             return dp[n]= 0;
//         if(n==1)
//             return dp[n]=v[0];
//         if(n==2)
//             return dp[n]=max(v[0],v[1]);
//         if(dp[n]!=-1)
//             return dp[n];
//         return dp[n]=max(solve(v,n-2,dp)+v[n],solve(v,n-1,dp));
//     }
// public:
//     int rob(vector<int>& nums) {
//         // int n =nums.size();
//         // vector<int>v(n);
//         // if(n==1)
//         //     return nums[0];
//         // if(n==2)
//         //     return max(nums[0],nums[1]);
//         // v[0]=nums[0];
//         // v[1]=max(nums[0],nums[1]);
//         // for(int i=2;i<n;i++){
//         //     v[i]=max(v[i-2]+nums[i],v[i-1]);
//         // }
//         vector<int>dp(1000,-1);
//         solve(nums,nums.size(),dp);
//         for(int i=0;i<10;i++){
//             cout<<dp[i]<<' ';
//         }
//         cout<<endl;
//         return dp[nums.size()];
//     }
// };



class Solution {
    public:
       // vector<int>dp(1000,-1);
        // int dp[1000];
       int solve(vector<int>&v, int n,vector<int>&dp){
        if(n==1){
            dp[n]=v[0];
            return dp[n];
        }
        if(n==2){
            dp[n]=max(v[0],v[1]);
            return dp[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = max(solve(v,n-2,dp)+v[n-1],solve(v,n-1,dp));
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(1000,-1);
        // memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size(),dp);
    }
};