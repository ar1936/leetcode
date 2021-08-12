class Solution {
    bool check(string s1,string s2){
        int bitmask1=0,bitmask2=0;
        for(auto x:s1){
            bitmask1 |= 1<<(x-'a');
        }
        for(auto x:s2){
            bitmask2 |= 1<<(x-'a');
        }
        return (bitmask1 & bitmask2)==0;
    }
public:
    int maxProduct(vector<string>& words) {
        int n=words.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(words[i],words[j])){
                    int a=words[i].size(),b=words[j].size();
                    ans=max(ans,a*b);
 
                }
            }
        }
        return ans;
    }
};