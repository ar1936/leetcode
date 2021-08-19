class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,prefix_sum=0;
        vector<int>reminder(k);
        reminder[0]=1;
        for(int i=0;i<n;i++){
            prefix_sum=(prefix_sum+10000*k+nums[i])%k;
            ans+=reminder[prefix_sum]++;
        }
        return ans;
    }
   
    
};


