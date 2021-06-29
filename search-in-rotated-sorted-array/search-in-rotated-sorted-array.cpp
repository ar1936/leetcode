class Solution {
    int b_s2(vector<int>nums,int ind,int target){
        int lo=ind,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return -1;
    }
    int b_s1(vector<int>nums,int ind, int target){
        int lo=0,hi=ind;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return -1;
    }
    public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else
                hi=mid;
        }
        return b_s1(nums,hi-1,target)==-1?b_s2(nums,hi,target):b_s1(nums,hi-1,target);
        // return hi;
    }
};