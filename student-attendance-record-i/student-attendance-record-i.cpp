class Solution {
public:
    bool checkRecord(string s) {
        int count_A=0,count_L=0,max_L=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A')
                count_A++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                count_L++;
                max_L=max(max_L,count_L);
            }
            else 
            {
                count_L=0;
            }
        }
        cout<<max_L<<" "<<count_A<<" ";
        if(max_L>=3)
            return false;
        if(count_A>=2)
            return false;
        return true;
    }
};