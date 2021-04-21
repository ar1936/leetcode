class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c0=-1,c1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                c0++;
            else if(nums[i]<0)
                c1++;
        }
        if(c0>=0)
            return 0;
        else if (c1%2!=0)
            return -1;
        return 1;
    }
};