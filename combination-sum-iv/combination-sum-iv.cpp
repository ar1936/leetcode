class Solution {
public:
     int combinationSum4(vector<int>& nums, int target) {
        unsigned int t[target+1];
        memset(t,0,sizeof(t));
        t[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j=1; j<=nums.size();j++) {
                if (i >=nums[j-1]) 
                    t[i] += t[i - nums[j-1]];
            }
        }
        
        return t[target];
    }
    
};

// class Solution {
// public:
//      int combinationSum4(vector<int>& nums, int target) {
//         vector<unsigned int> result(target + 1);
//         result[0] = 1;
//         for (int i = 1; i <= target; ++i) {
//             for (int x : nums) {
//                 if (i >= x) result[i] += result[i - x];
//             }
//         }
        
//         return result[target];
//     }
    
// };