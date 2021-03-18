class Solution {
public:
    
    int minSteps(int n) {
        int res=0,k=2;
        while(n>1){
            while(n%k==0)res+=k,n/=k;
            k++;
        }
        return res;
    }
};