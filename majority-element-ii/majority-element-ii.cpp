// class Solution {
//    int randRange(Random rand, int min, int max) {
//         return rand.nextInt(max - min) + min;
//     }

//      int countOccurences(int nums[], int num) {
//         int count = 0;
//         for (int i = 0; i < nums.length; i++) {
//             if (nums[i] == num) {
//                 count++;
//             }
//         }
//         return count;
//     }

//     public int majorityElement(int[] nums) {
//         Random rand = new Random();

//         int majorityCount = nums.length/3;
//         vector<int>ans;
//         while (true) {
//             int candidate = nums[randRange(rand, 0, nums.length)];
//             if (countOccurences(nums, candidate) > majorityCount) {
//                 ans.push_back(candidate);
//             }
//         }
//         return ans;
//     }
// }


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
		if (nums.empty()) return ans;
		// srand(time(NULL));
        for (int i = 0; i < 100; ++i) {
            int val = nums[rand() % nums.size()], cnt = 0;
            for (int j = 0; j < ans.size(); ++j) if (ans[j] == val) goto outer;
            for (int j = 0; j < nums.size(); ++j) if (val == nums[j]) ++cnt;
            if (cnt > nums.size() / 3) ans.push_back(val);   
outer:; }     
        return ans;
    }
};