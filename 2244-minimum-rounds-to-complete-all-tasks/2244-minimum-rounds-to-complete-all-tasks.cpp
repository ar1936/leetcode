class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        map<int,int>mp;
        for(auto x:tasks){
            mp[x]++;
        }
        for(auto x:mp){
            if(mp[x.first]<2)
                return -1;
            else if(mp[x.first]<=3){
                ans++;
            }
            else if(mp[x.first]>3){
                ans+=((mp[x.first]%3>=1)+mp[x.first]/3);
            }
        }
        return ans;
    }
};