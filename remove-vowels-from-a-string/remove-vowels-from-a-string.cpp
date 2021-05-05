class Solution {
public:
    string removeVowels(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                s.erase(s.begin()+i);
                i--;
            }
        }
        return s;
    }
};