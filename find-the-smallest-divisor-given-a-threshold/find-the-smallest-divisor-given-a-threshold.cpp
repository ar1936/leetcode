class Solution {
    bool solve(vector<int>nums,int mid,int target){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0)
                count+=nums[i]/mid;
            else
                count+=nums[i]/mid+1;
        }
        if(count<=target)
                return true;
        return false;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int lo=1,hi=1e9;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(solve(nums,mid,threshold))
                hi=mid;
            else
                lo=mid+1;
        }
        return hi;
    }
};