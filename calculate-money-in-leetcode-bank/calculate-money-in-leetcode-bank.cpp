class Solution {
public:
    int totalMoney(int n) {
        int count=0,ans=0,j=0;
        for(int i=1;i<=n;i++){
            if(i%7==1)
                count=j++;
            count++;
            ans+=count;
        }
        return ans;
    }
};