class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=p.size();
        vector<int>p_hashing(26),s_hashing(26);
        for(int i=0;i<n;i++){
            if(i<s.size())
                s_hashing[s[i]-'a']++;
            p_hashing[p[i]-'a']++;
        }
        if(s_hashing==p_hashing){
            ans.push_back(0);
        }
        for(int i=n;i<s.size();i++){
            if(i<s.size()){
                s_hashing[s[i-n]-'a']--;
                s_hashing[s[i]-'a']++;
                if(s_hashing==p_hashing){
                    ans.push_back(i+1-n);
                }
            }
        }
        return ans;
    }
};