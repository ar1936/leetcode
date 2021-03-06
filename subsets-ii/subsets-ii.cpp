class Solution {
public:
    vector<vector<int>>m;
    set<vector<int>>s;
    void solve(vector<int>nums,vector<int>v)
    {
        if(nums.size()==0)
        {
            
            if(s.find(v)==s.end())
            {
                sort(v.begin(),v.end());
                s.insert(v);
                m.push_back(v);
                
            }
            return ;
        }
        vector<int>v1=v,v2=v;
        v1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,v1);
        solve(nums,v2);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(nums,v);
        return m;
        
    }
};