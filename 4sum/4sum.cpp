class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans,temp;
        if(nums.size()<=3){
            return {};
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        set<vector<int>>st;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        for(auto x:st){
            temp.push_back(x);
        }
        
        return temp;
    }
};