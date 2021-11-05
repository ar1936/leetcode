class Solution {
    private double get_ans(double x, long n){
        if(n==0)
            return 1.0;
        double half=get_ans(x,n/2);
        if(n%2==0)
            return half*half;
        else
            return half*half*x;
    }
    public double myPow(double x, int n) {
        if(n<0){
            n=-n;
            x=1/x;
        }
        return get_ans(x,n);
    }
}