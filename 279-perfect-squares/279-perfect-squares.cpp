class Solution {
public:
    void myfun(int &res,int curr,int n){
        if(n==0){
            res=min(res,curr);
            return;
        }
       // if(n<0)return;
        for(int i=sqrt(n);i>=1;i--){
            int sqr=i*i;
            int k=n/sqr;
            int mod=n%sqr;
            if(n-k*sqr>=0)
            myfun(res,curr+k,n-k*sqr);
        }
    }
    int numSquares(int n) {
        int sr=sqrt(n);
        if(sr*sr==n)return 1;
        int res=INT_MAX;
        myfun(res,0,n);
         return res;
    }
};
