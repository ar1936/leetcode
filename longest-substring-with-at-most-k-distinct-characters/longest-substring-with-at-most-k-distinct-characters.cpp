class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int i=0,j=-1,ans=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp.size()>k){
                mp[s[++j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                    // j++;
                }
            }
            ans=max(ans,i-j);
        }
        return ans;
    }
};

// int lengthOfLongestSubstringKDistinct1(string s, int k) {
//     unordered_map<char, int> ctr;
//     int j = -1, maxlen = 0;
//     for (int i=0; i<s.size(); ++i) {
//         ++ctr[s[i]];
//         while (ctr.size() > k)
//             if (--ctr[s[++j]] == 0)
//                 ctr.erase(s[j]);
//         maxlen = max(maxlen, i - j);
//     }
//     return maxlen;
// }