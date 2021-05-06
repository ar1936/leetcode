//my approach
// wrong test case->"rick"      "kric"

// class Solution {
// public:
//     bool isLongPressedName(string name, string typed) {
//         unordered_map<char,int>mp;
//         for(int i=0;i<typed.size();i++){
//             mp[typed[i]]++;
//         }
//         for(int i=0;i<name.size();i++){
//             mp[name[i]]--;
//         }
//         for(int i=0;i<name.size();i++){
//             if(mp[name[i]]<0)
//                 return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (j==0 || typed[j] != typed[j - 1])
                return false;
        return i == m;
    }
};