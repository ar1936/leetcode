class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            long long prev=0,curr=i;
            while(ans.size() && __gcd((long long)ans.back(),curr)>1){
                prev=ans.back();
                curr=(curr*prev)/(__gcd(curr,prev));
                ans.pop_back();
            }
            ans.push_back(curr);
        }
        return ans;
    }
};

