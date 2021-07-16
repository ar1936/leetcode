// this is leetcode method 


class Solution {
    void solve(int remain_n,int k,vector<int>&temp,int next_start,vector<vector<int>>&ans){
        if(remain_n==0 && temp.size()==k ){
            ans.push_back(temp);
            return ;
        }
        else if(remain_n<0 ||temp.size()==k){
            return;
        }
        
        for(int i=next_start;i<9;i++){
            temp.push_back(i+1);
            solve(remain_n-i-1,k,temp,i+1,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(n,k,temp,0,ans);
        return ans;
    }
};



// in this method i simply find combination of size k and put in (nums) matrix then i find sum of all array present in (nums) if those sum ios equal to (n) then i simply intreset that array in ans;

// class Solution {
//     vector<vector<int>>nums,ans;
//     void solve(vector<int>&temp,int n, int k, int i){
//         if(temp.size()==k){
//             nums.push_back(temp);
//             return ;
//         }
//         if(i==n+1){
//             return ;
//         }
//         temp.push_back(i);
//         solve(temp,n,k,i+1);
//         temp.pop_back();
//         solve(temp,n,k,i+1);
//     }
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int>temp;
//         solve(temp,9,k,1);
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum=0;
//             for(auto x:nums[i]){
//                 sum+=x;
//             }
//             if(sum==n){
                
//                 ans.push_back(nums[i]);
//             }
//         }
//         return ans;
//     }
// };
