class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>v;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=nums[i];
            v.push_back(sum);
            for(int j=i+1;j<nums.size();j++){
                
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=left-1;i<right;i++){
            ans=(ans+v[i]);
            ans%=(1000000007);
        }
        return int(ans);
    }
};