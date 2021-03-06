// class Solution {
// public:
//     vector<vector<int>>ans;
//     bool noone(int x,int target)
//     {
//         if(target-x==0)
//             return true;
//         return false ;
//     }
//     void solve(vector<int>& nums,vector<int>v, int target)
//     {
//         int sum=target;
//         if(nums.size()==0)
//             return ;
//         if(target<0)
//             return ;
//         if(target==0)
//         {
//             ans.push_back(v);
//         }
        
//         for(int i=0;i<nums.size();i++)
//         {
            
//             if(noone(nums[i],target))
//                 v.push_back(nums[i]);
                
//             // nums.erase(nums.begin()+i);
//         }
        
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int>v;
//         solve(candidates,v,target);
//         return ans;
//     }
// };




class Solution {
public:
    
    vector<vector<int> >ans;
    void solve(vector<int>& candidates, int target,int index,vector<int> &v){
        if(target<0)
            return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> v;
        int index=0;
        solve(candidates,target,index,v);
        return ans;
    }
};

