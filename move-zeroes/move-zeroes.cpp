class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),count=0,j=0;
        for(int i=0;i<n;i++){
            if(!nums[i])
                count++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<count;i++){
            nums[j+i]=0;
        }
    }
};