class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k>s.size())
            return 0;
        // if(s=="aaaaaaaa"&&k==2)
        //    return 0;
        int ans=0;
        string temp=s.substr(0,k);
        set<char>st;
        for(int i=0;i<k;i++){
            st.insert(temp[i]);
            if(st.size()==k)
                ans++;
        }
        
        for(int i=k;i<s.size();i++){
            set<char>st;
            temp.erase(temp.begin()+0);
            temp.push_back(s[i]);
            for(int i=0;i<k;i++){
                st.insert(temp[i]);
                if(st.size()==k)
                    ans++;
            }
        }
        return ans;
    }
};