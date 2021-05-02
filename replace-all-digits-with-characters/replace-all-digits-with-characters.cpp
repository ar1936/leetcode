class Solution {
public:
    string replaceDigits(string s) {
        if(s.size()==1)
            return s;
        char c;
        for(int i=1;i<s.length();i++){
            if(i%2==1){
                c=s[i-1]+(s[i]-'0');
                s[i]=c;
            }
            
        }
        return s;
    }
};