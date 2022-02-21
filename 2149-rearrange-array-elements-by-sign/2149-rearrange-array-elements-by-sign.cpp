class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(auto x:nums){
            if(x>0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }
        int j=0,k=0;
        for(int i=0;i<nums.size();i+=2){
            nums[i]=pos[j];
            nums[i+1]=neg[j];
            j++;
        }
        return nums;
    }
};