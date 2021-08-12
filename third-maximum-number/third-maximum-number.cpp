class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        nums.clear();
        for(auto x:st){
            nums.push_back(x);
        }
        int n=size(nums);
        if(n<=2)
            return nums.back();
        return nums[n-3];
    }
};