#define MOD 1000000007
class Solution {
public:
    int dp[31][1001];
    int rolls(int d,int t,int f){
        if(d==0 && t==0) return 1;
        else if(d<=0 || t<=0 || d*f<t || d>t)return 0; //check if target is reachable
		//  As if dice > required_target , it's not possible
		//  and if dice*face(max with left dice)< required target , it's not possible
        else if(dp[d][t]) return dp[d][t];
        for(int i=1;i<=f;i++)
            dp[d][t]=(dp[d][t]+rolls(d-1,t-i,f))%MOD;    
        return dp[d][t]%MOD;
    }
    int numRollsToTarget(int d, int f, int target) {
        return rolls(d,target,f);
    }
};