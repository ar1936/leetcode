                    //Using sorting

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        vector<int>dp(n);
        dp=nums;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]!=nums[i]+1 && nums[j]!=nums[i]-1){
                    dp[i]=max(dp[i],dp[j]+nums[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

