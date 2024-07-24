class Solution {
    public:
        vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<mapping.size();i++){
            mp[i]=mapping[i];
        }
        vector<pair<pair<int,int>,int>>vv;
        vector<int>vp;
        for(int j=0;j<nums.size();j++){
            int x = nums[j];
            int ans = 0;
            int p = 0;
            if(x==0){
                ans = mp[x];
                vv.push_back({{ans,j},nums[j]});
            }
            else{
                 while(x!=0){
               int pp = x%10;
               ans=(mp[pp]*(pow(10,p))+ans);
                p++;
                x=x/10;
            }
            pair<int,int>vx = {ans,j};
            vv.push_back({vx,nums[j]});
            vp.push_back(ans);
            }
            
        }
        sort(vv.begin(),vv.end());
        vector<int>anss;
        for(int xp = 0;xp<vv.size();xp++){
            anss.push_back(vv[xp].second);
        }
        return anss;
    }
};

