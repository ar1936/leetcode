

class Solution 
{
public:
    vector<vector<int>>ans;
    void solve(vector<int>&op,int i,int n,int k)
    {
        if(op.size()==k)
        {
            ans.push_back(op);
            return;
        }
        if(i==n+1)
        {
            return;
        }
        op.push_back(i);
        solve(op,i+1,n,k);
        op.pop_back();
        solve(op,i+1,n,k);
    }
    vector<vector<int>>combine(int n, int k)
    {
        vector<int>op;
        solve(op,1,n,k);
        return ans;
    }
};