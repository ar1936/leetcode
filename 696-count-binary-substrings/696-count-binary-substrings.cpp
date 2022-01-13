class Solution {
public:
    int countBinarySubstrings1(string s) {
        vector<int>groups(s.size());
        int t=0;
        groups[t]=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                groups[++t]=1;
            }
            else{
                groups[t]++;
            }
        }
        int ans=0;
        for(int i=1;i<=t;i++){
            ans+=min(groups[i-1],groups[i]);
        }
        return ans;
    }
    int countBinarySubstrings(string s) {
        int ans=0,prev=0,curr=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
            else{
                curr++;
            }
        }
        return ans+min(curr,prev);
    }
};