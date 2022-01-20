class Solution {
    int find_max(string s, int i , char c){
        int idx=-1;
        char mx_char=c;
        for(;i<s.size();i++){
            if(c==s[i])
                continue;
            if(mx_char<=s[i]){
                idx=i;
                mx_char=s[i];
            }
        }
        return idx;
    }
public:
    int maximumSwap(int num) {
        int i=0;
        string s=to_string(num);
        while(i<s.size()&&s[i]=='9')
            i++;
        for(;i<s.size();i++){
            int idx=find_max(s,i,s[i]);
            if(idx==-1)
                continue;
            swap(s[idx],s[i]);
            break;
        }
        return stoi(s);
    }
};