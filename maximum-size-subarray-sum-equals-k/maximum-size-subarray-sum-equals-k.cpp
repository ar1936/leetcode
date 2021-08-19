class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
                ans=i+1;
            else if(mp.find(sum-k)!=mp.end())
                ans=max(ans,i-mp[sum-k]);
           if(mp.find(sum)==mp.end())
                mp[sum]=i;
        }
        return ans;
    }
};
