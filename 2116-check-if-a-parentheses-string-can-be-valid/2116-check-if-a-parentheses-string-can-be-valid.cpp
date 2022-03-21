// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         stack<char>st;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='('||s[i]=='['||s[i]=='{'){
//                 if()
//                 st.push(s[i]);
//             }
//             else if(s[i]==')'||s[i]==']'||s[i]=='}'){
//                 if(st.size()==0){
//                     if(locked[i]=='0'){
//                         return false;
//                     }
//                     else if(locked[i]=='0'){
//                         if(s[i]==')'){
//                             st.push('(');
//                         }
//                         else if(s[i]=='}'){
//                             st.push('{');
//                         }
//                         else{
//                             st.push('[');
//                         }
//                     }
//                 }
//                 else if(s[i]==')' && st.top()=='('){
//                     st.pop();
//                 }
//                 else if(s[i]==']' && st.top()=='['){
//                     st.pop();
//                 }
//                 else if(s[i]=='}' && st.top()=='{'){
//                     st.pop();
//                 }
//                 else {
//                     if(locked[i]=='1'){
//                         return false;
//                     }
//                     else {
//                         st.pop();
//                     }
//                 }
//             }
//         }
//         return st.size()==0;
//     }
// };




class Solution {
public:
      bool canBeValid(string s, string locked) {
          
        if (s.length() % 2 == 1) 
            return false;
          
        int unlocked = 0, open = 0, closed = 0, unpaired;
        for(int i = 0; i <s.length(); i++) {
            if (locked[i] == '0')
                unlocked++;
            else if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                closed++;
            unpaired = closed-open;
            if (unpaired > unlocked)
                return false;
        }
          
        unlocked = 0, open = 0, closed = 0, unpaired=0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if (locked[i] == '0')
                unlocked++;
            else if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                closed++;
            unpaired = open-closed;
            if (unpaired > unlocked)
                return false;
        }
          
        return true;
    }
};