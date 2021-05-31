class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,bal=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                bal+=1;
            else
                bal+=-1;
            if(bal==-1){
                ans++;
                bal++;
            }
        }
        return ans+bal;
    }
};