//2 pointer 


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_id = 0, t_id = 0;
        while(s_id < s.size() && t_id < t.size()) {
            t_id = t.find(s[s_id], t_id);
            if (t_id >= t.size()) {
                return false;
            }
            t_id++;
            s_id++;
        }
        return s_id == s.size();
    }
};
