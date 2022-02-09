class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<2)
            return 0;
        int left=0,right=1,ans=0;
        sort(nums.begin(),nums.end());
        while(left<nums.size() && right<nums.size()){
            if(left==right || nums[right]- nums[left]<k)
                right++;
            else if(nums[right]- nums[left]>k)
                left++;
            else{
                left++;
                ans++;
                while(left<nums.size() && nums[left]==nums[left-1])
                    left++;
            }
        }
        return ans;
    }
};