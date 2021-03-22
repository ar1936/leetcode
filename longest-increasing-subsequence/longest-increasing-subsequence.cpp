class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t (n+1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    t[i]=max(t[i],1+t[j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(t[i],ans);
        return ans;
    }
};