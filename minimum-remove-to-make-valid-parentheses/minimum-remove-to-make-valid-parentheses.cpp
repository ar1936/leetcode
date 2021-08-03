class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string ans="";
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);    
            }
            else if(!st.empty()&&s[i]==')'){
                    st.pop();
            }
            else if(s[i]==')') {
                s[i]='*';
            }
        }
          while (!st.empty()) {
            s[st.top()] = '*';
             st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
    
