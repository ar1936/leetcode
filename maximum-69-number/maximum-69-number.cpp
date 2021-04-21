class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='9')
            {
                s[i]='9';
                break;
            }
            
        }
        for(int i=0;i<s.size();i++)
        num=num*10+s[i]-'0';
    
        return num;
    }
};