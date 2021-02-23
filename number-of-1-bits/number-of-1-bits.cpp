class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m,count=0;
        while(n)
        {
             m=n;
            if(m%2!=0)
                count++;
           
            n/=2;
                
        }
        return count;
    }
};