// this is final one easy to remember


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>inc_dp(n,1),dec_dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    inc_dp[i]=max(inc_dp[i],1+inc_dp[j]);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dec_dp[i]=max(dec_dp[i],1+dec_dp[j]);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(inc_dp[i]>1&&dec_dp[i]>1)
            ans=max(ans,inc_dp[i]+dec_dp[i]-1);
        }
        return n-ans;
    }
};
