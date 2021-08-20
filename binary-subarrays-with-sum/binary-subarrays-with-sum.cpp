class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),ans=0,sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(i>0)
                nums[i]+=nums[i-1];
            ans+=mp[nums[i]-goal];
            mp[nums[i]]++;
        }
        return ans;
    }
};
