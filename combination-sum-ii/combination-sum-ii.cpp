class Solution {
    set<vector<int>>st;
    void solve(vector<int>&nums,vector<int>&temp,int target,vector<vector<int>>&ans,int index,int sum){
        if(sum==target){
            cout<<sum<<"\n";
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        else if(temp.size()==nums.size()||index==nums.size()||sum>target){
            return ;
        }
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,temp,target,ans,i+1,sum+nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,temp,target,ans,0,0);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};


