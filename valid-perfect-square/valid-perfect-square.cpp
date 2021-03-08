class Solution {
public:
    bool isPerfectSquare(int num) {
        if(abs(sqrt(num))-floor(sqrt(num))==0)
            return true;
        return false;
    }
};