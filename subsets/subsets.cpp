class Solution {
public:
    vector<vector<int>>v;
    void subset(vector<int>&nums,int i,vector<int>temp)
    {
        if(nums.size()==i)
        {
            v.push_back(temp);
            return ;
        }
        subset(nums,i+1,temp);
        temp.push_back(nums[i]);
        subset(nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    
        vector<int>temp;
        subset(nums,0,temp);
        return v;
    }
};