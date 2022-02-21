class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,num=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                num=nums[i];
            }
            count+=(num==nums[i]?1:-1);
        }
        return num;
    }
};