class Solution {
public:
    map<string ,int>mp;
    vector<string>v;
    void solve(string in,string op)
    {
        if(in.size()==0)
        {
            mp[op]++;
            return ;
        }
        string op1=op,op2=op;
        if(in[0]>='a'&&in[0]<='z')
        {
            op1.push_back(in[0]-('a'-'A'));
            op2.push_back(in[0]);
            
        }
        else if (in[0]>='A'&&in[0]<='Z')
        {
            op1.push_back(in[0]+('a'-'A'));
            op2.push_back(in[0]);
        }
        else 
        {
            op1.push_back(in[0]);
            op2.push_back(in[0]);
        }
        in.erase(in.begin()+0);
        solve(in,op1);
        solve(in,op2);
        
    }
    vector<string> letterCasePermutation(string in) {
    string op="";
    solve(in,op);
        for(auto x:mp)
        {
            v.push_back(x.first);
        }
        
        return v;
    }
};