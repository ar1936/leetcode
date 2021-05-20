class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0,temp=1;
        for(int i=1;i<=10;i++){
            temp*=5;
            ans+=n/temp;
            if(temp>=n)
                break;
        }
        return ans;
    }
};