class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(int first, vector<int>& nums){
        if (first == nums.size()) ans.push_back(nums);
        else{
            for (int i = first; i < nums.size(); i++){
                swap(nums[first], nums[i]);
                backtracking(first + 1, nums);
                swap(nums[first], nums[i]);
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(0, nums);
        return ans;
    }
};