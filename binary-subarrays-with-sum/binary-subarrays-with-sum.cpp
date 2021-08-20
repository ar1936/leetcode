class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),ans=0,sum=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};