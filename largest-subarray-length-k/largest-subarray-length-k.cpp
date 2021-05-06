class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int index=0,temp=-1;
        
        if(k==nums.size())
            return nums;
        for(int i=0;i<=nums.size()-k;i++){
            if(temp<nums[i]){
                index=i;
                temp=nums[i];
            }
        }
        vector<int>v;
        for(int i=0;i<k;i++){
            v.push_back(nums[index+i]);
        }
        return v;
    }
};