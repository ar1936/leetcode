class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.length()>1){
            if(s.back()=='1'){
                int j = s.size()-1;
                while(j>=0 && s[j]=='1'){
                    s[j] = '0';
                    j-=1;
                }
                if(j<0){
                    s.insert(s.begin(),'1');
                }
                else{
                    s.insert(s.begin()+j, '1'); 
                    s.pop_back();
                }
            }
            else{
                s.pop_back();
            }
            ans+=1;
        }
        return ans;
    }
};