class Solution {
    bool solve(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i]<v[i-1])
                return false;
        }
        return true;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size(),p=1<<n;
        vector<vector<int>>temp(p),ans;
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1)
                    temp[i].push_back(nums[j]);
            }
        }
        set<vector<int>>st;
        for(int i=0;i<temp.size();i++){
            if(temp[i].size()>=2 && solve(temp[i]))
                st.insert(temp[i]);
        }
        for(auto x:st)
                ans.push_back(x);
        return ans;
    }
}; 
