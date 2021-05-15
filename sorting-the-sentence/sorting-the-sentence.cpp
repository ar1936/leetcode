class Solution {
public:
    string sortSentence(string s) {
        string str="";
        int count=0,x,y=0,z;
        z=s[s.size()-1]-'0';
        unordered_map<int,string>mp;
        for(int i=0;i<s.size();i++){

            if ((s[i]>='a'&&s[i]<='z')||s[i]>='A'&&s[i]<='Z'){
                str+=s[i];
            }
            else if(s[i]==' '){
                x=s[i-1]-'0';
                mp[x]=str;
                y++;
                str.clear();
            }
        }
        mp[z]=str;
        str.clear();
        for(int i=1;i<=y+1;i++)
            str+=mp[i]+" ";
        str.pop_back();
        return str;
    }
};