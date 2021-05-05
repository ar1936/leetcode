class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char,int>mp;
        int count=0;
        for(int i=0;i<keyboard.size();i++){
            mp[keyboard[i]]=i;
        }
        int x=0;
        count=mp[word[0]];
        for(int i=1;i<word.size();i++){
            x=abs(mp[word[i-1]]-mp[word[i]]);
            count+=x;
        }
        return count;
    }
};