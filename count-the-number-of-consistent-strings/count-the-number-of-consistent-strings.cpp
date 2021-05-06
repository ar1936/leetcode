class Solution {
public:
    bool solve(string a,string b){
        unordered_set<char>s;
        for(int i=0;i<b.size();i++){
            s.insert(b[i]);
        }
        int m=a.size();
        int i=0;
        while(m--){
            if(s.find(a[i])==s.end())
                return false;
            i++;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            if(solve(words[i],allowed))
                count++;
        }
        return count;
    }
};