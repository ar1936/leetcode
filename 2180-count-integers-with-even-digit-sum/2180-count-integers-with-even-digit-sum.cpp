class Solution {
    int digits_sum(int n){
        int sum =0;
        while(n){
            sum=sum+(n%10);
            n/=10;
        }
        return sum;
    }
    void solve(vector<int>&dp, int num){
        for(int i=1;i<=num;i++){
            int temp=digits_sum(i);
            if(temp%2==0){
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
    }
public:
    int countEven(int num) {
        vector<int>dp(1001,0);
        solve(dp,num);
        return dp[num];
    }
};