class Solution {
    vector<vector<int>>nums,ans;
    void solve(vector<int>&temp,int n, int k, int i){
        if(temp.size()==k){
            nums.push_back(temp);
            return ;
        }
        if(i==n+1){
            return ;
        }
        temp.push_back(i);
        solve(temp,n,k,i+1);
        temp.pop_back();
        solve(temp,n,k,i+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(temp,9,k,1);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(auto x:nums[i]){
                sum+=x;
            }
            if(sum==n){
                
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};