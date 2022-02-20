// My try
// edge test case :- [[3,10],[4,10],[5,11]]   or [[1,2],[1,4],[3,4]]
// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         int ans=0;
//         sort(intervals.begin(),intervals.end());
//         for(int i=1;i<intervals.size();i++){
//             if(intervals[i-1][0]<=intervals[i][0] && intervals[i-1][1]>=intervals[i][1]){
//                 ans++;
//                 intervals[i][0]=intervals[i-1][0];
//                 intervals[i][1]=intervals[i-1][1];
//             }
//         }
//         return intervals.size()-ans;
//     }
// };

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0,left=-1,right=-1;
        for(auto x:intervals){
            if(x[0]>left && x[1]>right){
                ans++;
                left=x[0];
            }
            right=max(right,x[1]);
        }
        return ans;
    }
};

