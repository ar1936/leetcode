// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
// //         if(matrix[0][0]=='1'&&matrix.size()==1)
// //             return 1;
//                 int t[m+1][n+1];
//         memset(t,0,sizeof(t));
//         int x=INT_MIN;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0)
//                 {
//                     if(matrix[i][j]=='1')
//                     t[i+1][1]=1;
//                     x=max(x,t[i+1][1]);
//                 }
//                  if(j==0)
//                 {
//                     if(matrix[i][j]=='1')
//                     t[i+1][1]=1;
//                     x=max(x,t[i+1][1]);
//                 }            
//             }
            
//         }
//         if(m==1||n==1)
//             return x;
        
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(matrix[i-1][j-1]=='1')
//                 {
//                     t[i][j]=min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]))+1;
//                     x=max(m,t[i][j]);
//                 }
//                 else 
//                     t[i][j]=0;
//             }
//         }
//         if(x==2)
//             return x*x;
//         else
//         return x*x/4;
//     }
// };





class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        int max=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                }
                
                if(dp[i][j]>max)
                {
                    max=dp[i][j];
                }
            }
        }
        return max*max;
    }
};