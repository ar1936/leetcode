class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size(),i=0,j=0;
        if(n>m)
            return false;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else
                j++;
        }
        return i==n;
    }
};