//                     //Using sorting

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         int n=nums.size(),ans=0;
//         sort(nums.begin(),nums.end());
//         vector<int>dp(n);
//         dp=nums;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[j]!=nums[i]+1 && nums[j]!=nums[i]-1){
//                     dp[i]=max(dp[i],dp[j]+nums[i]);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
// };


                // Using house robbor 

class Solution {
    int house_robber(vector<int>v){
        for(int i=2;i<v.size();i++){
            v[i]=max(v[i-1],v[i-2]+v[i]);
  
        }
        return v[v.size()-1];
    }
 
    
public:
    int deleteAndEarn(vector<int>& nums) {
        int v_size=0;
        for(int i=0;i<nums.size();i++){
            v_size=max(nums[i],v_size);
        }
        
        // here we can take size of vector(v) =10000 (1 <= nums[i] <= 10^4) but for optimum size of vector v we need to find max value in nums
        
        
        vector<int>v(v_size+1);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]+=nums[i];
        }
        return house_robber(v);
    }
};