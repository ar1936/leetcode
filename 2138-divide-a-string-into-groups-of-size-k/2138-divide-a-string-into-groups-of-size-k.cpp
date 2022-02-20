class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(temp.size()==k){
                ans.push_back(temp);
                temp="";
            }
        }
        if(s.size()%k!=0){
            while(temp.size()<k){
                temp.push_back(fill);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};