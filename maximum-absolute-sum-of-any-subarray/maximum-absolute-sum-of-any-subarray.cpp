class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0)
                sum=0;
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(-1*nums[i]);
            ans=max(ans,sum);
            if(sum<0)
                sum=0;
        }
        return ans;
    }
};