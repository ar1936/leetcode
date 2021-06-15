class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int ans=100000;
        map<int,int>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]++;
            }
        }
        for(auto x:mp){
            if(x.second==mat.size()){
                ans=min(ans,x.first);
            }
        }
        
        return ans==100000?-1:ans;
    }
};