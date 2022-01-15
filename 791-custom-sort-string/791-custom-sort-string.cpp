class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        vector<int>v(26);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<order.size();i++){
            for(int j=0;j<v[order[i]-'a'];j++){
                ans+=order[i];
            }
        }
        map<char,int>mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=1;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};