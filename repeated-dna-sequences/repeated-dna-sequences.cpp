class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        vector<string>ans;
        if(s.size()<10)
            return{};
//         if(s.size()==10){
            
//             ans.push_back(s);
//             return ans;
//         }
        for(int i=0;i<s.size()-9;i++){
            mp[s.substr(i,10)]++;
        }
        for(auto x:mp){
            if(x.second>=2){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};