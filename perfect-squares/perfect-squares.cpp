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
        
        if(n==0)return 0;
        int sqrt_n = sqrt(n);
        int perfectSquares[sqrt_n];
        for(int i=1;i<=sqrt_n;i++)
        {
            perfectSquares[i-1] = i*i;
        }
        
        int t[n+1];
        t[0] = 0;
        for(int i=1;i<=n;i++)
        {
            t[i] = INT_MAX;
            for(int s : perfectSquares)
            {
                if(i-s<0)break;
                
                t[i] = min(t[i],t[i-s]+1);
            }
        }
        
        return t[n];
    }
};