// class Solution {
// public:
//     int numSquares(int n) {
//         int  x=sqrt(n);
//         int t[x+1];
//         for(int i=0;i<=x;i++)
//         {
//             t[i]=i*i;
//         }
//         int count=0;
//         int i=x;
//         for(int i=x;i>=0;i--)
//         {
//             if(n>t[i])
//             {
//                 n-=t[i];
//                 count++;
//             }
//             else if (n==t[i])
//             {
//                 count++;
//                 break;
//             }
//         }
        
// //         while(n>=1)
// //         {
// //             if(n>=t[i])
// //             {
// //                 count++;
// //                 n-=t[i];
                
// //             }
// //             else if(n==t[i])
// //             {
// //                 count++;
// //                 break;
// //             }
// //             else 
// //                 i--;
// //         }
//         return count;
//     }
// };





class Solution {
public:
  int numSquares(int n) {
    
    vector<int>dp(n+1, INT_MAX-1);
     vector<int>coins;
    for(int i=1; i<=sqrt(n); i++)
    {
        coins.push_back(i*i);
    }
     dp[0]=0;
    for(int i=1; i<=n;i++)
    {
        for(int j=0; j<coins.size(); j++)
        {
            if(i>=coins[j])
            {
                dp[i]=min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    return dp[n];
    
                            
}
};