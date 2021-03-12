// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int low=0,high=nums.size()-1;
//         if(nums[0]>nums[1])
//             return 0;
//         if(nums[nums.size()-1]>nums[nums.size()-2])
//             return nums.size()-1;
//         while(low<=high)
//         {
//             int  mid=low+(high-low)/2;
//             if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])
//                 return mid;
//             else if (nums[mid-1]>nums[mid])
//                 high=mid-1;
//             else 
//                 low=mid+1;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0, high = num.size() - 1;
        while (low < high - 1) {
            int mid = (low + high) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) 
                return mid;
            else if (num[mid] > num[mid + 1]) 
                    high = mid - 1;
                 else 
                    low = mid + 1;    
        }
        return num[low] > num[high] ? low : high;
    }
};