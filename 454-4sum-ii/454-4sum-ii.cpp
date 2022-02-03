class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(),ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp.find(-nums3[i]-nums4[j])!=mp.end())
                    ans+=mp[-nums3[i]-nums4[j]];
            }
        }
        return ans;
    }
    
    
//     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//         unordered_map<int, int>  abSum;
//         for(auto a : A) {
//             for(auto b : B) {
//                 ++abSum[a+b];
//             }
//         }
//         int count = 0;
//         for(auto c : C) {
//             for(auto d : D) {
//                 // auto it = abSum.find(0 - c - d);
//                 if(abSum.find(c+d) != abSum.end()) {
//                     count +=abSum[-c-d];
//                 }
//             }
//         }
//         return count;
//     }
};

