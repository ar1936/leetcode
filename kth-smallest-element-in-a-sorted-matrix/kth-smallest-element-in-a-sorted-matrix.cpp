// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n=matrix.size();
//         int i=0,j=n-1,count=0;
//         priority_queue <int> pq;
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     pq.push(matrix[i][j]);
//                     if(pq.size()>k)
//                         pq.pop();
//                 }
//             }
//         return pq.top();
        
//     }
// };




class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int rows = a.size();
        int cols = a[0].size();
        int start = a[0][0];
        int end = a[rows-1][cols-1];
        while(start<end) {
            int mid = (start+end)/2;
            int j = cols-1;
            int cnt = 0;
            for (int i = 0; i<rows; i++) {
                while(j>=0 and a[i][j] > mid) {
                    j--;
                }
                cnt += (j+1);
            }
            if (cnt < k) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};