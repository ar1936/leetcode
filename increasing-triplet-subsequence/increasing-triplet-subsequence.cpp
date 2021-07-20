class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=a;
        for(auto x:nums){
            if(a>=x)
                a=x;
            else if(b>=x)
                b=x;
            else
                return true;
        }
        return false;
    }
};