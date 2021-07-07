// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         set<char>st;
//         int n=s.size(),prev_repeat_index=0,ans=0;
//         if(n<=1)
//             return n;
//         st.insert(s[0]);
//         for(int i=1;i<n;i++){
//             st.insert(s[i]);
//             if(st.find(s[i])==st.end()){
//                 st.insert(s[i]);
//             }
//             else
//             {
//                 for (; s[prev_repeat_index] != s[i]; prev_repeat_index++) {
//                     st.erase(s[prev_repeat_index]);
//                 };
//                 prev_repeat_index++;
//             }
//             if(ans<=st.size())
//                 ans=st.size();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, L = 0, size = s.size(), setLen;
        if (size <= 1) {
            return size;
        }
        unordered_set<char> letterSet = { s[0] };
        for (int R = 1; R < size; R++) {
            if (letterSet.find(s[R]) == letterSet.end()) {
                letterSet.insert(s[R]);
            }
            else {
                for (; s[L] != s[R]; L++) {
                    letterSet.erase(s[L]);
                };
                L++;
            }
            setLen = letterSet.size();
            maxLen = max(maxLen, setLen);
        }
        return maxLen;
    }
};