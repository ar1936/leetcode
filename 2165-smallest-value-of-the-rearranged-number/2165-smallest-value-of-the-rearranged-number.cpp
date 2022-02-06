class Solution {
public:
    long long smallestNumber(long long num) {
        bool flag=false;
        if(num>0)
            flag=true;
        else
            flag=false;
        string s=to_string(num),str="";
        if(flag){
            sort(s.begin(),s.end());
            if(s[0]=='0'){
                int count=0,i=0;
                for(;i<s.size();i++){
                    if(s[i]=='0'){
                        count++;
                    }
                    else{
                        str+=s[i];
                        break;
                    }
                }
                while(count){
                    str+='0';
                    count--;
                }
                i++;
                for(;i<s.size();i++){
                    str+=s[i];
                }
                s=str;
                cout<<s<<"\n";
            }
        }
        else{
            sort(s.begin(),s.end());
            reverse(s.begin(),s.end());
            // cout<<s<<'\n';                
        }
        // num=stoi(s);
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='-')
                ans=ans*10+(s[i]-'0');
            cout<<(s[i]-'0')<<" ";
        }
        if(flag)
            return ans;
        // return -6333221000;
        return -1*ans;
    }
};