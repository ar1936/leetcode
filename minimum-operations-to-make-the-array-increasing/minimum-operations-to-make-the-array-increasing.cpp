class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1)
            return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=(nums[i-1])){
                int m=nums[i-1];
                ans+=abs(nums[i]-m)+1;
                nums[i]=m+1;
            }    
        }
        return ans;
    }
};