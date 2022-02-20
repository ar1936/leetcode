class Solution {
public:
    int countElements(vector<int>& nums) {
        int mn=INT_MAX,mx=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        for(auto x:nums){
            if(x>mn && x<mx)
                ans++;
        }
        return ans;
    }
};