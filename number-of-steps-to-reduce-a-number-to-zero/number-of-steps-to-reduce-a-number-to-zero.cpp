class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0)
            return 0;
        int count=-1;
        while(num){
            if(num%2!=0)
                count++;
            num=num/2;
            count++;
        }
        return count;
    }

    
};