class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       
        int left=0,right,k=1;
        for( right =0;right<nums.size();right++){
            if(nums[right]==0)
                k--;
            if(k<0){
                if(nums[left]==0)k++;
                    left++;
                
            }
        }
        return right-left;
    }
};
        
