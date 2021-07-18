class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1])
                    v[i][j]=v[i-1][j-1]+1;
                else
                    v[i][j]=0;
            }
        }
        int ans=0;
        for(auto x:v){
            for(auto y:x){
                ans=max(y,ans);
            }
        }
        return ans;
    }
};