class Solution {
public:
    int kthGrammar(int n, int k) {
        
    if(n==1||k==1)
    return 0;
    int m=pow(2,n-1)/2;
    if(m>=k)
    return kthGrammar(n-1,k);
    else
    return !kthGrammar(n-1,k-m);
    return 0;
        
    }
};