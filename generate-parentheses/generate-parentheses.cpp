class Solution {
public:
    void solve(string &str,int open_count,int close_count,vector<string> &ans){
        if(open_count==0 && close_count==0){
            ans.push_back(str);
            return;
        }
        if(open_count>0){
            str.push_back('(');
            solve(str,open_count-1,close_count,ans);
            str.pop_back();
        }
        
        if(close_count>open_count){
            str.push_back(')');
            solve(str,open_count,close_count-1,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        solve(str,n,n,ans);
        return ans;
    }
};