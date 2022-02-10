class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        for(auto x:nums){
            ans+=mp[x-k];
            mp[x]++;
        }
        return ans;
    }
};



// 1 -> 260
// 2 -> 280
    
// 1 3 6 
