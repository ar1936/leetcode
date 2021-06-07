class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
            return nums[0];
        if(size==2)
            return max(nums[size-1],nums[size-2]);
        for(int i=1;i<size;i++){
            int mx=0;
            for(int j=0;j<i-1;j++){
                mx=max(mx,nums[j]);
            } 
            nums[i]+=mx;
        }
            return max(nums[size-1],nums[size-2]);
    }
};