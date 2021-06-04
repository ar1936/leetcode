class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>temp(groupSizes.size()+1),ans;
        for(int i=0;i<groupSizes.size();i++){
            temp[groupSizes[i]].push_back(i);
            if(temp[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back({});
                swap(ans.back(),temp[groupSizes[i]]);
            }
        }
        return ans;
    }
};
