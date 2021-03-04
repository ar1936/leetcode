class Solution {
public:
//     int solve(string s,int n,int i)
//     {
//         if(n==1)
//             return 5;
//         if(i==0)
//             n=n-1;
        
//         if(s[i]>s[i-1])
//             return solve(s,n,i-1)+1;
//         return 0;
//     }
    int countVowelStrings(int n) {
       
        n++;
        return n*(n+1)*(n+2)*(n+3)/24;
    }
};