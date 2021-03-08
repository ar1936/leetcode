// class Solution {
// public:
//     int findMin(vector<int>& nums) {\
//         int ans=nums[0];
//         int low=0,high=nums.size()-1;
//         int n=nums.size();
//         while(low<high)
//         {
//             int mid=low+(high-low)/2;
//             if((nums[mid]<nums[(mid+1)%n])&&(nums[mid]<nums[(mid-1+n)%n]))
//             return nums[mid];
//             else if(nums[mid]>=nums[low])
//                low=mid+1;
//             else if(nums[mid]<=nums[high])
//                high=mid-1;
               
//         }
//                return ans;
        
//     }
// };


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]<nums[high]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
       
        return nums[high];
    }
};