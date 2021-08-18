class Solution {
public:
//     int numberOfSubarrays(vector<int>& A, int k) {
//         return atMost(A, k) - atMost(A, k - 1);
//     }

//     int atMost(vector<int>& A, int k) {
//         int res = 0, i = 0, n = A.size();
//         for (int j = 0; j < n; j++) {
//             k -= A[j] % 2;
//             while (k < 0){
//                 k += A[i] % 2;
//                 i++;
//             }
//             res += j - i + 1;
//         }
//         return res;
//     }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%2;
        }
        for (int i = 0; i < n; ++i) {
            mpp[sum]++;
            sum += nums[i];
            res += mpp[sum - k];
        }
        return res;
    }
};


