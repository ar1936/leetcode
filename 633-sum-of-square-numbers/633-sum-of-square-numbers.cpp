class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            if(floor(sqrt(c-i*i))==ceil(sqrt(c-i*i)))
                return true;
        }
        return false;
    }
};