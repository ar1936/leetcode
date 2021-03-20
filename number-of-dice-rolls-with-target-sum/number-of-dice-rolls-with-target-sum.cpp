// #define MOD 1000000007
// class Solution {
// public:
//     int dp[31][1001];
//     int rolls(int d,int t,int f){
//         if(d==0 && t==0) return 1;
//         else if(d<=0 || t<=0 || d*f<t || d>t)return 0; //check if target is reachable
// 		//  As if dice > required_target , it's not possible
// 		//  and if dice*face(max with left dice)< required target , it's not possible
//         else if(dp[d][t]) return dp[d][t];
//         for(int i=1;i<=f;i++)
//             dp[d][t]=(dp[d][t]+rolls(d-1,t-i,f))%MOD;    
//         return dp[d][t]%MOD;
//     }
//     int numRollsToTarget(int d, int f, int target) {
//         return rolls(d,target,f);
//     }
// };

// #define mod 1000000007
// class Solution {
// public:
//     int numRollsToTarget(int d, int f, int target) {
//         // int mod = pow(10,9)+7;
//         vector<vector<int>> t(d+1, vector<int>(target+1, 0));
//         t[0][0] = 1;
//         for(int i = 1; i <= d ;i++){
//             for(int j = 1; j <= target ; j++){
//                 for(int k = 1; k <= f; k++){
//                     if(j >= k){
//                         t[i][j] = (t[i][j] + t[i-1][j-k])%mod;
//                     }
//                 }
//             }
//         }
//         return t[d][target];
//     }
// };

// class Solution {
//     public int numRollsToTarget(int d, int f, int T) {
//         int mod=1000000007;
//         long dp[][]=new long[d+1][T+1];
        
//         dp[0][0]=1;
        
//         for(int i=1;i<=d;i++){
//             dp[i][0]=0;
//             for(int j=1;j<dp[0].length;j++){
                
//                 for(int k=1;k<=f;k++){
//                     if(k>j)continue;
//                     dp[i][j]+=dp[i-1][j-k];
//                     dp[i][j]%=mod;
//                 }
//             }
//         }
//         return (int)(dp[d][T]);
//     }
// }

class Solution {
public:
   int numRollsToTarget(int d, int f, int target) {
int mod=1000000007;
// lo t[d+1][target+1];
    vector<vector<long long> > t(d+1,vector<long long>(target+1));
t[0][0]=1;
for(int i=1;i<=d;i++)
{
t[i][0]=0;
for(int j=1;j<target+1;j++){
for(int k=1;k<=f;k++)
{
if(k>j)continue;
t[i][j]+=t[i-1][j-k];
t[i][j]%=mod;

}
}
}

return (int)t[d][target];
    }
};

