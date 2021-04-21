class Solution {
public:
    int digit(int num){
        int count=0;
        while(num){
            num/=10;
            count++;
        }
        return count;
    }
    bool isArmstrong(int n) {
        int m=n,d=digit(n),sum=0;
        while(n){
            sum+=pow(n%10,d);
            n/=10;
        }
        
        return sum==m;
    }
};