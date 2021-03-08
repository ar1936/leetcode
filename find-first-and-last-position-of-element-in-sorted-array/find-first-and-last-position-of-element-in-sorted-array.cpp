class Solution {
public:
    int f(const vector<int>& nums, int target,bool bound){
        int left = 0, right = nums.size()-1, ret = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                ret = mid;
                if(bound) left = mid+1;
                else right = mid-1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {f(nums,target,false),f(nums,target,true)};     
    }
};