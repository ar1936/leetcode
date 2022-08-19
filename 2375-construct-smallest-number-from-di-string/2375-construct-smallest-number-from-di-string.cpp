class Solution {
public:
//     string smallestNumber(string s) {
//         string ans="";
//         vector<int>v;
//         v.push_back(0);
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='I')
//                 v.push_back(i+1);
//             ans+=(i+'1');
//         }
        
//         ans+=(s.size()+'1');
//         v.push_back(s.size()+1);
//         for(auto x:v){
//             cout<<x<<" ";
//         }
//         if(v.size()==2){
//             reverse(ans.begin(),ans.end());
//             return ans;
//         }
//         else if(v.size()==s.size()+2){
//             return ans;
//         }
//         for(int i=1;i<=v.size();i++){
//             reverse(ans.begin()+v[i-1],ans.begin()+v[i]);
//         }
        
//         return ans;
//     }
    string smallestNumber(string s) {
        string res;
        int n = s.size(), j = 0;
        for (int i = 0; i <= s.size(); ++i) {
            res.push_back('1' + i);
            if (i == n || s[i] == 'I') {
                reverse(res.begin() + j, res.end());
                j = i + 1;
            }
        }
        return res;
    }
};

