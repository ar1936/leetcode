class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp1,win;
        vector<int>ans_win,ans_lost;
        set<int>s1,s2;
        for(auto x:matches){
            mp1[x[0]]++;
            mp1[x[1]]++;
            win[x[0]]++;
        }
        for(auto x:matches){
            if(mp1[x[0]]==win[x[0]]){
                s1.insert(x[0]);
            }
            if(mp1[x[1]]==win[x[1]]+1){
                s2.insert(x[1]);
            }
        }
        for(auto x:s1){
            ans_win.push_back(x);
        }
        for(auto x:s2){
            ans_lost.push_back(x);
        }
        sort(ans_win.begin(),ans_win.end());
        sort(ans_lost.begin(),ans_lost.end());
        return {ans_win,ans_lost};
    }
};