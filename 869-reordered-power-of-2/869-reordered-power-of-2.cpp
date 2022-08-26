class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>pow_of_two;
        int tmp =1;
        string s;
        while(tmp<=1e9+7){
            s = to_string(tmp);
            sort(s.begin(),s.end());
            pow_of_two.push_back(s);
            if(tmp==n)
                return true;
            tmp=tmp*2;
        }
        s = to_string(tmp);
        sort(s.begin(),s.end());
        pow_of_two.push_back(s);
        s = to_string(n);
        sort(s.begin(),s.end());
        for(auto x:pow_of_two){
            if(x==s)
                return true;
        }
        return false;
    }
};