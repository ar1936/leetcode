class Solution {
public:
    vector<string> sol;
    int N;
    void util(int i,string ans)
    {
        if((int)ans.size()==N)
        {
            sol.push_back(ans);
            return;
        }
        if(i==0||ans[i-1]!='a')
        {
            ans.push_back('a');
            util(i+1,ans);
            ans.pop_back();
        }   
        if(i==0||ans[i-1]!='b')
        {
            ans.push_back('b');
            util(i+1,ans);
            ans.pop_back();
        }
        if(i==0||ans[i-1]!='c')
        {
            ans.push_back('c');
            util(i+1,ans);
            ans.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        N=n;
        util(0,"");
        int len=(int)sol.size();
        if(k>len) return "";
        return sol[k-1];
    }
};

