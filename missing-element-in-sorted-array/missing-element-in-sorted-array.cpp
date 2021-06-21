class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            int temp=k;
            k-=(nums[i]-nums[i-1]-1);
            if(i==nums.size()-1&&k>0){
                return nums[i]+k;
            }
            if(k<=0){
                if(temp+nums[i-1]>=nums[i]){
                    return temp+nums[i-1]+1;
                }
                else if(temp+nums[i-1]<nums[i]){
                    return temp+nums[i-1];
                }
            }
        }
        return ans=0;
    }
};