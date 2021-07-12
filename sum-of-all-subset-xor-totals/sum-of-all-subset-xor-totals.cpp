class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),p=1<<n;
        vector<vector<int>>ans(p);
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1)
                    ans[i].push_back(nums[j]);
            }
        }
        int res=0,temp = 0;
        for(int i=0;i<ans.size();i++){
            temp=0;
            for(auto x:ans[i]){
                temp^=x;
            }
            res+=temp;
        }
        return res;
    }
};