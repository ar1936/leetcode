class Solution {
public:
    
    bool checkPerfectNumber(int num) {
        int sum=1,temp=0;
        if(num==1)
            return false;
        for(int i=2;i<sqrt(num);i++){
            if(num%i==0){
                sum+=i;
                sum+=(num/i);
            }
        } 
        return sum==num;
    }
};