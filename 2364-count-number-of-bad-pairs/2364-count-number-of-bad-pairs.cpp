class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good=0,n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            good+=mp[i-nums[i]];
            mp[i-nums[i]]++;
        }
        return n*(n-1)/2 -good;
    }
};