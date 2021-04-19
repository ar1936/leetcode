class Solution {
public:
    bool solve(vector<char>v){
        if(v.size()==1)
            return true;
        for(int i=0;i<v.size()/2;i++){
            if(v[i]!=v[v.size()-i-1])
                return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        vector<char>v;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]>='0'&&s[i]<='9')
                v.push_back(s[i]);
        }
        // for(auto x:v)
        //     cout<<x;
        return solve(v);
    }
};