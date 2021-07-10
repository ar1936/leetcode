class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(double i=1;i<=n;i++){
            for(double j=1;j<=n;j++){
                for(double k=1;k<=n;k++){
                    if(i*i+j*j==k*k)
                        ans+=1;
                }
            }
        }
        return ans;
    }
};