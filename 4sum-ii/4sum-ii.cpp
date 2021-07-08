// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int ans=0,n=nums1.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 for(int k=0;k<n;k++){
//                     for(int l=0;l<n;l++){
//                         if(nums1[i]+nums2[j]+nums3[k]+nums4[l]==0)
//                             ans++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        // support variables
        int res = 0;
        unordered_map<int, int> abMap, cdMap;
        // populating abMap and cdMap as frequency tables of sums
        for (int i: a) for (int j: b) abMap[i + j]++;
        for (int i: c) for (int j: d) cdMap[i + j]++;
        // making sure we loop through the smaller of the 2
        if (abMap.size() > cdMap.size()) swap(abMap, cdMap);
        // finding if we have opposite matches in abMap and cdMap
        for (auto e: abMap) {
            // otherwise we update res
            res += e.second * cdMap[-e.first];
        }
        return res;
    }
};