class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1,temp;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
            temp=-1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[j-1])
                {
                    temp=j-i+1;
                    ans=max(ans,temp);
                }
                else
                {  
                    
                    break;
                }
            }
        }
        return ans;
    }
};