class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
            ans+=(n-i);
        }
        return ans;
    }
};