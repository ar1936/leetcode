class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // support variables
        vector<string> res;
        int len = nums.size(), i = 0, j;
        string tmp;
        while (i < len) {
            // moving j right after the last sequential element after i
            j = i + 1;
            while (j < len && nums[j - 1] + 1 == nums[j]) j++;
            // composing and appending the next element to res, then settin i for the next loop
            tmp = to_string(nums[i]) + (j - i > 1 ? "->" + to_string(nums[j - 1]) : "");
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
};