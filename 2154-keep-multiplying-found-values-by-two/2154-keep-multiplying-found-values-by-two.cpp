class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        while(st.find(original)!=st.end()){
            original=2*original;
        }
        return original;
    }
};