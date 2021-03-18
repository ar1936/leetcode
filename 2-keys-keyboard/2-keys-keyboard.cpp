class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        return primeFactors(n);
            
    }
    
    int primeFactors(int n) {
        int sum = 0;
        while(n % 2 == 0) {
            sum += 2;
            n /= 2;
        }
        
        for(int i=3;i<=n;i+=2) {
            while(n % i == 0) {
                sum += i;
                n /= i;
            } 
        }
        return sum;
    }
};