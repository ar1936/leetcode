//  similar to c_sum 3 with some extra condition
    

// class Solution {
//     set<vector<int>>st;
//     void solve(vector<int>&nums,vector<int>&temp,int target,vector<vector<int>>&ans,int index,int sum){
//         if(sum==target){
//             sort(temp.begin(),temp.end());
//             st.insert(temp);
//             return;
//         }
//         else if(temp.size()==nums.size()||index==nums.size()||sum>target){
//             return ;
//         }
//         for(int i=index;i<nums.size();i++){
//             temp.push_back(nums[i]);
//             solve(nums,temp,target,ans,i+1,sum+nums[i]);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>ans;
//         vector<int>temp;
//         solve(nums,temp,target,ans,0,0);
//         for(auto x:st){
//             ans.push_back(x);
//         }
//         return ans;
//     }
// };



class Solution {
    void solve(vector<int>nums,vector<int>&temp,int remain_target, int index, vector<vector<int>> &ans){
        if(remain_target==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index  &&  nums[i]==nums[i-1])
                continue;
            int pick=nums[i];
            if(remain_target-pick<0){
                break;
            }
            temp.push_back(pick);
            solve(nums,temp,remain_target-pick,i+1,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums,temp,target,0,ans);
            return ans;
    }
};
