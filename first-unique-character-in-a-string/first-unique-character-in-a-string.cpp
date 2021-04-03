class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        int m=10e6;
        for(int i=s.size();i>=0;i--){
            mp[s[i]]++;
           
            
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};