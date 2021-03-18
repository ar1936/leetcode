// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=INT_MAX,sum=0;
//         int n=triangle.size();
//         int t[n+1];
//         t[0]=0;
//         t[1]=triangle[0][0];
//         for(int i=2;i<=n;i++)
//         {
//             m=INT_MAX;
//             for(int j=0;j<triangle[i-1].size();j++)
//             {
//                 m=min(m,triangle[i-1][j]);
                
//             }
//             t[i]=t[i-1]+m;
//         }
//         return t[n];
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j< triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};