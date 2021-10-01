class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        sort(strs.begin(),strs.end());
        string a=strs[0],b=strs.back();
        string ans="";
        for(int i=0;i<b.size();i++){
            if(a[i]==b[i])
                ans+=b[i];
            else
                break;
        }
        return ans;
    }
};