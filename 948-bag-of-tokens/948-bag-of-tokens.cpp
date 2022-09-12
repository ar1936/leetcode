class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)
            return 0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,ans=0,tmp=0;
        if(tokens[0]>power){
            return 0;
        }
        while(i<tokens.size() && j>=0){
            if(power>=tokens[i]){
                power-=tokens[i];
                tmp++;
                i++;
            }
            else{
                power+=tokens[j];
                tmp--;
                j--;
            }
            ans=max(tmp,ans);
            // cout<<i<<" "<<j<<" "<<power<<' '<<ans<<"\n";
        }
        return ans;
    }
};