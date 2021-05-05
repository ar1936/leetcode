class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool flag = true;
        int ans=1,ans0=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {   
                count++;
                flag=false;
            }
            else
                ans0*=nums[i];
                ans*=nums[i];
        }
        if(flag){
            for(int i=0;i<nums.size();i++){
               int x=nums[i];
                nums[i]=ans/x;
            }
        }
        else if(!flag)
        {
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0)
                    nums[i]=ans0;
                else
                    nums[i]=0;
            }
        }
        if (count>=2)
        {
            for(int i=0;i<nums.size();i++){
                nums[i]=0;
            }
        }
        return nums;
    }
};