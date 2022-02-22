class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(s.size()<k)
            return 0;
        int ans=0;
        map<char,int>mp;
        for(int i=0;i<k;i++){
            mp[s[i]]++;
        }
        if(mp.size()==k)
            ans++;
        for(int i=k;i<s.size();i++){
            mp[s[i-k]]--;
            mp[s[i]]++;
            if(mp[s[i-k]]==0)
                mp.erase(s[i-k]);
            if(mp.size()==k)
                ans++;
        }
        return ans;
    }
};