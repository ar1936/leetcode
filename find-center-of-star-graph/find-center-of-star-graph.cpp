class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[0].size();j++){
                mp[edges[i][j]]++;
            }
        }
        for(auto x:mp){
            if(x.second==edges.size())
                return x.first;
        }
        return 0;
    }
};