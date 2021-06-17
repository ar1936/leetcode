                // MY try

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int ans=0,count_0=0,last_zero=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 count_0++;
//             }
//             if(count_0==k){
//                 ans=max(ans,i+1-last_zero);
//                 count_0=0;
//                 last_zero=i;
//             }
//         }
//         return ans;
//     }
// };


                    // by LC solutions 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right;
        for( right =0;right<nums.size();right++){
            if(nums[right]==0)
                k--;
            if(k<0){
                if(nums[left]==0)k++;
                    left++;
                
            }
        }
        return right-left;
    }
};