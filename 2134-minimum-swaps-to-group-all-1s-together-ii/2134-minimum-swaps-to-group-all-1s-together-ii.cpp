class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0,count=0,ans=67864578;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                k++;
        }
        for(int i=0;i<k;i++){
           if(nums[i%nums.size()]==1){
                count++;
            }
        }
        ans=min(ans,k-count); 
        for(int i=k;i<2*nums.size();i++){
            if(nums[i%nums.size()]==1){
                count++;
            }
            if(nums[(i-k)%nums.size()]==1){
                count--;
            }
            ans=min(ans,k-count);
        }
        return ans;
    }
};