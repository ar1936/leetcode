class Solution {
public:
    vector<vector<int> >m;
    set<vector<int> >s;
    void solve(vector<int>nums,int i)
    {
        if(i==nums.size())
        {
            if(s.find(nums)==s.end())
            {
                s.insert(nums);
                m.push_back(nums);
                
            }
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            solve(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return m;
        
    }
};