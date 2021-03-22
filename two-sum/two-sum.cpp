class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[target-nums[i]]=i;
            }
            else
                return {mp[nums[i]],i};
            
        }
        return {0,0};
    }
};