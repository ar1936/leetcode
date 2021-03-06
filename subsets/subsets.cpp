class Solution {
public:
    vector<vector<int> >m;
    void solve(vector<int>nums,vector<int>op)
    {
        if(nums.size()==0)
        {
            m.push_back(op);
            return;
        }
        vector<int>op1=op,op2=op;
        op1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,op1);
        solve(nums,op2);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        solve(nums,op);
        return m;
        
    }
};