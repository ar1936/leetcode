//my try

// class Solution {
// public:
//     bool isValid(string s) {
        
//         int n=s.size();
//          if(s[n-1]=='['||s[n-1]=='{'||s[n-1]=='(')
//             return false;
//         stack<char>st;
//         for(int i=0;i<s.size();i++){
//             if((s[i]==']'||s[i]=='}'||s[i]==')')&&st.empty())
//             return false;
//             if(s[i]=='(')
//                 st.push(s[i]);
//             else if (s[i]==')'&&st.top()=='(')
//                 st.pop();
//             if(s[i]=='[')
//                 st.push(s[i]);
//             else if (s[i]==']'&&st.top()=='[')
//                 st.pop();
//             if(s[i]=='{')
//                 st.push(s[i]);
//             else if (s[i]=='}'&&st.top()=='{')
//                 st.pop();
            
//         }
//         return st.size()==0;
//     }
// };


//neha gupta solution 
class Solution {
public:
bool isValid(string s) {
     stack<char> st;
     int n = s.size();
     for(int i=0;i<n;i++)
     {   
         if(s[i]=='(' || s[i]=='{' || s[i]=='[')
         { 
           st.push(s[i]);
           continue;
         }
         if(st.empty())
             return false;
         char x = st.top();
         if((x=='(' && s[i]==')') || (x=='{' && s[i]=='}') || (x=='[' && s[i]==']'))
             st.pop();
         else
            return false;
     } 
     
     return st.empty();
 }
};