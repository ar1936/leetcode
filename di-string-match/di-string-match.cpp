class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0,k=0,n=s.size(),j=s.size();
        vector<int>v(n+1);
        while(k<n){
            if(s[k]=='I')
                {
                    v[k]=i;
                    i++;
                }
            else
                {
                    v[k]=j;
                    j--;
                }
            k++;
        }
        v[k]=i;
        return v;
    }
};