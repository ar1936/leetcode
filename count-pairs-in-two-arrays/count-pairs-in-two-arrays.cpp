class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff(nums1.size());
        
        for (int i = 0; i < nums1.size(); i++) 
            diff[i] = nums1[i] - nums2[i];
        
        sort(diff.begin(), diff.end());
        
        long long ans = 0;
        
        int l = 0;
        int r = diff.size()-1;
        while(l<r){
             if (diff[l]+diff[r] > 0){
                   ans += (r-l);
                   r--;
             }else{
                  l++;
             }
        }
        
        
        return ans;
    }
};
