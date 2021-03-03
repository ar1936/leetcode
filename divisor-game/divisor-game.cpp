class Solution {
public:
    bool divisorGame(int n) {
        if(n%2==0)
            return true;
        else 
            return false;
        // for(int i=n;i!=1;i--)
        // {
        //     if(n%i==0)
        //     {
        //        divisorGame(n-i);
        //     }
        // }
        return true;
         
    }
};