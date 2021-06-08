                // bruth force using recursion;
//                 Complexity Analysis

//                 Time complexity : O(n!)O(n!). \text{calculate}()calculate() will be called maximum n!n! times.
//                 Space complexity : O(n)O(n). Recursion of depth nn is used.

// class Solution {
//     int solve(vector<int>nums,int index,bool flag){
//         int max_count=0;
//         for(int i=index+1;i<nums.size();i++){
//             if((flag&&nums[i]>nums[index])||(!flag&&nums[i]<nums[index])){
//                 max_count=max(max_count,1+solve(nums,i,!flag));
//             }
//         }
//         return max_count;
//     }
//     public:
//     int wiggleMaxLength(vector<int>& nums){
//         if(nums.size()<2)
//             return nums.size();
//         return 1+max(solve(nums,0,true),solve(nums,0,false));
//     }
// };


class Solution {
    public:
    int wiggleMaxLength(vector<int>& nums){
        if(nums.size()<2)
            return nums.size();
        vector<int>up_dp(nums.size()),down_dp(nums.size());
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    up_dp[i]=max(up_dp[i],down_dp[j]+1);
                }
                else if(nums[i]<nums[j])
                    down_dp[i]=max(down_dp[i],up_dp[j]+1);
            }
        }
        return max(up_dp[nums.size()-1],down_dp[nums.size()-1])+1;
    }
};


