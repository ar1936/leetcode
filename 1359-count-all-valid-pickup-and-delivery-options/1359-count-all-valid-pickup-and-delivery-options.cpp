class Solution {
public:
    int countOrders(int n) {
        vector<long long>fac(501);
        long long ans=1;
        int mod =1e9+7;
        fac[1]=1;
        for(int i=2;i<=500;i++){
            fac[i]=((fac[i-1]%mod)*i)%mod;
            
        }
        for(int i=1;i<2*n+1;i+=2){
            ans=(ans*i)%mod;
        }
        return (ans*fac[n])%mod;
    }
};