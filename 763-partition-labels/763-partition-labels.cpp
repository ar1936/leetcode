class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last(26);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        int j=0,temp=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            j=max(j,last[s[i]-'a']);
            if(i==j){
                ans.push_back(i-temp+1);
                temp=i+1;
            }
        }
        return ans;
    }
};