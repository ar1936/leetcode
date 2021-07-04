class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>nums.size()/3)
                s.insert(nums[i]);
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};