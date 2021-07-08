class Solution {
public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>>ans,temp;
//         if(nums.size()<=3){
//             return {};
//         }
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     for(int l=k+1;l<n;l++){
//                         if(nums[i]+nums[j]+nums[k]+nums[l]==target){
//                             ans.push_back({nums[i],nums[j],nums[k],nums[l]});
//                         }
//                     }
//                 }
//             }
//         }
//         for(int i=0;i<ans.size();i++){
//             sort(ans[i].begin(),ans[i].end());
//         }
//         set<vector<int>>st;
//         for(int i=0;i<ans.size();i++){
//             st.insert(ans[i]);
//         }
//         for(auto x:st){
//             temp.push_back(x);
//         }
        
//         return temp;
//     }
// };

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    int lo = start, hi = nums.size() - 1;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            ++lo;
        else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            --hi;
        else
            res.push_back({ nums[lo++], nums[hi--]});
    }
    return res;
}
    
};