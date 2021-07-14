// class Solution {
// public:
//     vector<vector<int>> combinationSum3(int k, int m) {
//         vector<int>nums(k);
//         for(int i=0;i<k;i++){
//             nums[i]=(i+1);
//         }
        
//         int n=k, p=1<<n;
//         vector<vector<int>>temp(p),ans;
        
//         for(int i=0;i<p;i++){
//             for(int j=0;j<k;j++){
//                 temp[i].push_back(nums[j]);
//             }
//         }
//         int sum=0;
        
//         for(int i=0;i<p;i++){
//             sum=0;
//             if(temp[i].size()==k){
//                 for(auto x:temp[i]){
//                     sum+=x;
//                 }
//             }
//             if(sum==m){
//                 ans.push_back(temp[i]);
//             }
//         }
//         return temp;
//     }
// };

class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
};